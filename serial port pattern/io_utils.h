enum class INTERRUPT_FLAGS_E{ENABLE_RX_ENABLE_TX=0x1,
                                ENABLE_RX_DISABLE_TX_MASK=0x2,
                                DISABLE_RX_DISABLE_TX_MASK=0x4,
                                RECEIVED_DATA_BIT=0x8,
                                TRANSMITTER_EMPTY_BIT=0x10,
                                PENDING_INTERRUPT_BIT=0x32};

class IO_Utils
{
public:
    static void io_write(long statusRegister, INTERRUPT_FLAGS_E mask);
    static long io_read(long statusRegister);
    static void send_event(EventType event, int);
};