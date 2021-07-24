#include <queue>
#include "buffer.h"

template <typename T>
class MsgQueue
{
public:
    virtual void    push(T msg);
    virtual T       pop();
    virtual long    getLength() const;
private:
    std::queue<T>  _msgQ;
};

class IMessage
{
public:
    virtual long    length() = 0;
};

// class IReciever
// {
// public:
    
// private:
//     SerialPort::Buffer _receiverBuffer;
// };

// class ITransmitter
// {
// public:
//     void transmit();
// private:
//     SerialPort::Buffer _transmitBuffer;
// };

//-----------------------------------------------------------------------

class SerialPort
{
protected:
    void HandleRxInterrupt();
    void HandleTxInterrupt();

public:
    SerialPort(long baseAdrr, int portID);
    ~SerialPort();

    // Event Handler that is invoked when the ISR has finished transmitting
    // a message
    void HandleTransmissionCompleteCallBack();
    // Event Handler that is invoked when the ISR has received a new message
    void HandleReceiveCompleteCallBack();
    // This handler is invoked by higher layers when they wish to transmit
    // a message over the serial link
    void HandleTxMessage(IMessage* msg);
    // Check the interrupt status register to determine if some
    // interrupt is pending
    bool IsInterruptPending();
    // This method is executed from the ISR. It checks the interrupt
    // status register to determine the exact source of interrupt.
    void HandleInterrupt();

private:
   // Queues for receiving and transmitting messages
   MsgQueue<IMessage*>  _receiveQueue;
   MsgQueue<IMessage*>  _transmitQueue;
   
   
   // Buffers used for store data when the ISR is receiving or transmitting data
   Buffer   _receiveBuffer;
   Buffer   _transmitBuffer;
   
   // Addresses for device registers
   const long   _interruptStatusRegister;    // Register to manage interrupts
   const long   _transmitDataRegister;       // Register to copy data to be transmitted
   const long   _receiveDataRegister;        // Register to obtain received data
   
   const int    _portId;                      // Id assigned to this serial port
};
