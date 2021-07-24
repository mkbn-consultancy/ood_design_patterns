#include "serialPortManager.h"

template <size_t MAX_SERIAL_PORT>
void SerialPortManager<MAX_SERIAL_PORT>::HandleInterruptEvent(const SerialPortManager<MAX_SERIAL_PORT>::Event *pEvent)
{
      SerialPort *pPort = _serialPort[pEvent->portID];
      
      switch (pEvent->type)
      {
      case EventType::TRANSMISSION_COMPLETE:
         pPort->HandleTransmissionComplete();
         break;
         
      case EventType::RECEIVE_COMPLETE:
         pPort->HandleReceiveComplete();
         break;
      }
}   

// Interrupt Service Routine for all interrupts
template <size_t MAX_SERIAL_PORT>
void SerialPortManager<MAX_SERIAL_PORT>::InterruptServiceRoutine()
{
   bool foundInterruptSource = false;
   
   // Loop through all the serial ports to find out which serial device
   // generated this interrupt. (Multiple device interrupts might be
   // generated at the same time)
   for (i=0; i < MAX_SERIAL_PORTS; i++)
   {
      if (_serialPort[i].IsInterruptPending())
      {
         foundInterruptSource = true;
         _serialPort[i].HandleInterrupt();
      }
   }
   
   // Interrupt was raised but no device was found with a pending
   // interrupt. Raise the spurious interrupt counter
   if (!foundInterruptSource)
   {
      _spuriousInterruptCount++;
   } 
}
