#include "fileLogger.h"
#include "consoleLoggerDecorator.h"
#include "IDELoggerDecorator.h"

int main() 
{
    ILogger* lg = new ConsoleLoggerDecorator( new IDELoggerDecorator( new FileLogger));
    lg->sendMsg("Hello World");
}