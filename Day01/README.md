首先在一个服务器系统中写日志，就是把一些数据写到终端或者文件中去。为了梳理整个流程，我们先把日志写到终端，走一遍整个流程，之后我们再一步步优化。

# 日志格式
日志包含以下几个重要数据即可
1. 时间 
2. 进程PID
3. 日志级别
4. 日志内容
5. 所在文件名，行号
这些数据就可以满足基本要求了

# 日志使用
对于C++来说，流式输出是最符合习惯的，也最方便，所以我们也采用这种方式
`LOG_INFO << "hello,log;`

# Log类
写日志，说白了，就是把一些字符写到一个字符串当中去，然后输出出来。如果这样的话，我们就封装一个Log类，里面包含输出日志的接口，之后具体实现可以更改，接口是不变的。

# 极简实现
查看Day01的代码

# 测试
```
int main()
{
    LOG_INFO << "hello,log";
    LOG_INFO << 11111;
    LOG_INFO << 1.000;
    LOG_INFO << true;
}
```
输出结果
![](https://cdn.jsdelivr.net/gh/liukboy/PicBed@main/img/WX20231030-222534@2x.png)
