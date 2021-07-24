#include "serialPort.h"
#include "io_utils.h"
#include "messageFactory.h"
#include <iostream>

SerialPort::SerialPort(long baseAdrr, int portID)
                              : _interruptStatusRegister(baseAdrr),
                              _transmitDataRegister(baseAdrr+1),
                              _receiveDataRegister(baseAdrr+2),
                              _portId(portID)
{
   _receiveBuffer.length = 0;
   _receiveBuffer.currIndex = 0;
   _transmitBuffer.length = 0;
   _transmitBuffer.currIndex = 0;
   // Note: Receive interrupt is always enabled, as data can be received
   //       at any time. Transmit interrupt is enabled only when transmitting
   //       data on the serial link.
   IO_Utils::io_write(_interruptStatusRegister, INTERRUPT_FLAGS_E::ENABLE_RX_DISABLE_TX_MASK);
   
   // Initialize pointers to associated queues
}

SerialPort::~SerialPort()
{
   IO_Utils::io_write(_interruptStatusRegister, INTERRUPT_FLAGS_E::DISABLE_RX_DISABLE_TX_MASK);
}

void SerialPort::HandleTxMessage(IMessage *pMsg)
{
   // Add the message to the transmit queue
   _transmitQueue.push(pMsg);
   
}

// Called when the ISR has finished processing the
// current message and it is ready to process another one.
void SerialPort::HandleTransmissionCompleteCallBack()
{
   // Check for more messages to transmit
   IMessage *pMsg = _pTransmitQueue->pop();
   
   if (pMsg)
   {
       // Message found for transmission, set up the transmit
       // buffer
       _transmitBuffer.length = pMsg->length();
       _transmitBuffer.currIndex = 0;
       
       // Copying data for tranmisson
       memcpy(_transmitBuffer.data, pMsg, pMsg->length());
   }
   else  
   {
       // No more messages pending for transmission, so disable the
       // transmit interrupt.
       IO_Utils::io_write(_interruptStatusRegister, INTERRUPT_FLAGS_E::ENABLE_RX_DISABLE_TX_MASK); 
   }   
}

// Called when ISR has received a complete message
void SerialPort::HandleReceiveCompleteCallBack()
{
   // Allocate a buffer for the message and copy the contents
   // from the receive buffer
   IMessage *pMsg = MsgFactory::getNewMessage(_receiveBuffer.data, _receiveBuffer.length);
   // memcpy(pMsg, m_receiveBuffer.data, m_receiveBuffer.length);
   // Copy the length of the message
   // pMsg->length = m_receiveBuffer.length;  
   // Pass the message to the higher layers
   _pReceiveQueue->push(pMsg);
   
   // Cleanup the message buffer for receiving the next message
   _receiveBuffer.currIndex = 0;   
}

void SerialPort::HandleInterrupt()
{  
   int interruptStatus = IO_Utils::io_read(_interruptStatusRegister);
   
   if (interruptStatus & INTERRUPT_FLAGS_E::RECEIVED_DATA_BIT)
   {
      HandleRxInterrupt();
   }
   else if (interruptStatus & INTERRUPT_FLAGS_E::TRANSMITTER_EMPTY_BIT)
   {
      HandleTxInterrupt();
   }
   // else
   // {
   //    _spuriousInterruptCounter++;
   // }      
} 

// Receive interrupt handler
void SerialPort::HandleRxInterrupt()
{
   long data;
   
   // Read the received byte from the device
   data = IO_Utils::io_read(_receiveDataRegister);
   
   // Check if this is the first byte. The first
   // byte contains the total length of the message
   if (_receiveBuffer.currIndex == 0)
   {
      _receiveBuffer.length = data;
   }
   
   // Copy the bytes into the receive buffer
   _receiveBuffer.data[_receiveBuffer.currIndex++] = data;
   
   // Check if the complete message has been received, if so
   // raise an event to notify the protocol task.
   if (_receiveBuffer.currIndex == _receiveBuffer.length)
   {
      IO_Utils::send_event(EventType::RECEIVE_COMPLETE, _portId);
   }    
}

// Transmit Interrupt Handler
void SerialPort::HandleTxInterrupt()
{
   // Get the byte to be transmitted
   char data = 
       _transmitBuffer.data[_transmitBuffer.currIndex++];
   
   // Write the byte to the transmit register    
   IO_Utils::io_write(_transmitDataRegister, data);
   
   // Check if the complete message has been transmitted, if so
   // raise an event to notify the protocol task
   if (_transmitBuffer.currIndex == _transmitBuffer.length)
   {
      send_event(EventType::TRANSMISSION_COMPLETE, _portId);
   }
}

bool SerialPort::IsInterruptPending()
{   
   int interruptStatus = IO_Utils::io_read(_interruptStatusRegister);
   return (interruptStatus & INTERRUPT_FLAGS_E::PENDING_INTERRUPT_BIT);
}


