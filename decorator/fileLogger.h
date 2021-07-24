#ifndef __FILE_LOGGER_H__
#define __FILE_LOGGER_H__

#include "logger.h"

// #include <string> 
#include <iostream> //for debugging

class FileLogger : public ILogger
{
public:
    FileLogger() = default;

    virtual void sendMsg(const std::string& msg) override{ 
        std::cout << "[log file] writing message to log file: "<<msg<<"...\n";
    }
};

#endif //__FILE_LOGGER_H__