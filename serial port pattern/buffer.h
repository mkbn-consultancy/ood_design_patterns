// Common Buffer structure for Transmit and Receive Buffers
struct Buffer
{
    enum {BUFFER_SIZE = 256};

    int     currIndex;
    int     length;
    char    data[BUFFER_SIZE];
};

