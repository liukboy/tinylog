# tinylog
A lightweight and easy-to-use C++1 logging library
- api简单。同步输出日志，只需要关注Logger类；异步输出日志，关注AsyncLogging类即可。
- << 流式输出。
- 日志分级。分为DEBUG，INFO，WARN，ERROR四种级别
- 滚动日志。跨天和日志内容满了自动新建文件。
- 引入简单。生成库或者直接拷贝源代码，无复杂配置。
- TODO：需要做一下性能测试。


#### 1. 简介
主要目的用于学习，实现一个简易日志库。但是麻雀虽小，五脏俱全，日志库基本操作都有，不过存在一些细节上的补充与修复。

#### 2. 目录说明
Day01~Day04:日志源文件。表示日志库搭建过程，每天实现一小部分，并且每个目录的README阐述了每一天的改进思路。 Day04是最终版本。
test: 存放测试代码源文件
Day*/CMakeLists.txt: 在每个build目录下执行cmake都可以生成可执行文件进行测试

#### 3. 测试代码编译运行
在Day*/build目录下执行
```
cmake .
make
```
此时会在build/test目录下生成等可执行文件，执行即可运行

#### 4. 使用说明
1. 生成静态库使用
2. 直接拷贝Day04的源文件，和自己的工程一起编译即可
```
#include "AsyncLogging.h"
#include "Logger.h"
int ROLL_SIZE = 500 * 1000 * 1000;
std::unique_ptr<AsyncLogging> logging;

void asyncout(const char *msg, size_t len)
{
    logging->append(msg, len);
}

int main(int argc, char *argv[])
{
    logging = std::make_unique<AsyncLogging>(::basename(argv[0]), ROLL_SIZE);
    logging->start();
    Logger::set_output_fun(asyncout);
    for (int i = 0; i < 100; ++i)
    {
        LOG_INFO << "Hello 12312313";
    }
    return 0;
}
```
格式说明
![](https://cdn.jsdelivr.net/gh/liukboy/PicBed@main/img/WX20231031-102601@2x.png)

#### 4. 各个模块解析
[博客解析](https://liukboy.github.io/tags/log/)

#### 5. TODO
作为个人开发而言，该库提供的功能已经基本满足使用。如果需要部署在公司，那么还远远不够。
1. Latency benchmark。与其它日志库性能比对
2. 支持设置日志最大保存时长，自动清理过期日志

