#include "Logger.h"
#include <iostream>
int main()
{
    LOG_INFO << "hello,log";
    LOG_DEBUG << 5;
    LOG_WARN << 2.000;
    LOG_ERROR << true;
    return 0;
}