#ifndef __ILOGGER_H__
#define __ILOGGER_H__

#include <string>

class ILogger
{
public:
    virtual void sendMsg(const std::string& str) = 0;
};

#endif //__ILOGGER_H__