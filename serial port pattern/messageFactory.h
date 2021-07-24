//forward declaration
class IMessage;

class MsgFactory
{
public:
    static IMessage* getNewMessage(const char*, int);
};
