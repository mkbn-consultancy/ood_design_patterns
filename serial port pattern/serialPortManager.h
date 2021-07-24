template <size_t MAX_SERIAL_PORT>
class SerialPortManager
{
public:
    enum class EventType{TRANSMISSION_COMPLETE,RECEIVE_COMPLETE};
public:
    struct Event
    {
        long        portID;
        EventType   type;
    };
public:
    SerialPortManager();
    ~SerialPortManager();

    void f();
    void HandleInterruptEvent(const SerialPortManager<MAX_SERIAL_PORT>::Event *pEvent);
    void InterruptServiceRoutine();

private:
    inline SerialPort   _ports[MAX_SERIAL_PORT];
};

