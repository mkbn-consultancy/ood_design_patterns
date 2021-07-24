#ifndef __CONSOLDELOGGER_H__
#define __CONSOLDELOGGER_H__

#include "loggerDecorator.h"
#include <iostream> //for debugging

class ConsoleLoggerDecorator : public LoggerDecorator
{
public:
    ConsoleLoggerDecorator(ILogger* wrappee) : LoggerDecorator(wrappee){}

    virtual void sendMsg(const std::string& msg){
        std::cout<<"[console] sending log message to console...\n";
        LoggerDecorator::sendMsg(msg);
    }
};

#endif //__CONSOLDELOGGER_H__