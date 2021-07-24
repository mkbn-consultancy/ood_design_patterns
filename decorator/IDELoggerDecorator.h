#ifndef __IDELOGGERDECORATOR_H__
#define __IDELOGGERDECORATOR_H__

#include "loggerDecorator.h"
#include <iostream> //for debugging

class IDELoggerDecorator : public LoggerDecorator
{
public:
    IDELoggerDecorator(ILogger* wrappee) : LoggerDecorator(wrappee){}

    virtual void sendMsg(const std::string& msg){
        std::cout<<"[ide] sending log message to ide...\n";
        LoggerDecorator::sendMsg(msg);
    }
};
#endif //__IDELOGGERDECORATOR_H__