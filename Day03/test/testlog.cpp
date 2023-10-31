#include "Logger.h"
#include "LogFile.h"
#include <iostream>

LogFile file("testlog", 4000 * 1024);

void fileoutput(const char *log, size_t len)
{
    file.append(log, len);
}

int main()
{
    Logger::set_output_fun(fileoutput);
    for (int i = 0; i < 10000; i++)
    {
        LOG_INFO << "1234567890qwertyuiopasdfghjklzxcvbnm";
    }
    file.flush();
    return 0;
}