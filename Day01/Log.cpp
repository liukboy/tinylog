
#include "Log.h"

#include <chrono>
#include <ctime>
#include <unistd.h> // 包含获取进程号的头文件

const string levels[Logger::LEVEL_NUM] =
    {"[DEBUG] ", "[INFO]  ", "[WARN]  ", "[ERROR] "};

Logger::Logger(const string &filename, int line) : log_in_file_name_(filename), line_(line)
{
    // 先把时间，进程PID，日志级别写到buf_中去
    setTime();
    setPID();
    setLogLevel(INFO);
}

void Logger::setTime()
{
    // 获取当前时间点
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    // 转换为时间结构
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    // 使用本地时间
    std::tm localTime = *std::localtime(&time);

    // 格式化为字符串
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S ", &localTime);
    buf_.append(buffer);
}
void Logger::setPID()
{
    buf_.append(to_string(getpid()));
    buf_.push_back('  ');
}

void Logger::setLogLevel(LogLevel level)
{
    buf_.append(levels[level]);
}

void Logger::log()
{
    cout << buf_;
}
// 析构的时候把日志输出
Logger::~Logger()
{
    buf_.append("      " + log_in_file_name_ + " : " + to_string(line_));
    buf_.push_back('\n');
    log();
}