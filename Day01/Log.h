/*
 * @Author: liukboy wowkliu@163.com
 * @Date: 2023-10-30 19:19:21
 * @Description: 极简流式日志
 *
 * Copyright (c) 2023 by liukboy, All Rights Reserved.
 */
#pragma once
/*

*/
#include <string>
#include <iostream>

using namespace std;

class Logger
{
public:
    enum LogLevel
    {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        LEVEL_NUM
    };
    using self = Logger;

public:
    Logger(const string &filename, int line);
    ~Logger();

    // 填充时间
    void setTime();
    // 填充进程号
    void setPID();
    // 设置日志级别
    void setLogLevel(LogLevel level);

    /*
    输出字符串buf_到终端
    */
    void log();

    /*
    重载一些 << 运算符，当使用 << 的时候，其实就是把数据 append到buf中去
    */
    template <typename T>
    self &operator<<(T val)
    {
        buf_.append(to_string(val));
        return *this;
    }

    self &operator<<(string &val)
    {
        buf_.append(val);
        return *this;
    }
    self &operator<<(const char *val)
    {
        buf_.append(val);
        return *this;
    }

private:
    string buf_;
    string log_in_file_name_; // 所在文件名字
    int line_;                // 行号
};

#define LOG_INFO \
    Logger(__FILE__, __LINE__)