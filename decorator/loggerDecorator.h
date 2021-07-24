#ifndef __LOGGERDECORATOR_H__
#define __LOGGERDECORATOR_H__

#include "logger.h"

class LoggerDecorator : public ILogger
{
public:
    LoggerDecorator(ILogger* wrappee) : _wrappee{wrappee}{}
    virtual void sendMsg(const std::string& msg) override{
        _wrappee->sendMsg(msg);
    }
private:
    ILogger* _wrappee;
};

#endif //__LOGGERDECORATOR_H__