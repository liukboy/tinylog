昨天实现的日志功能，有几个功能点是有严重问题的
1. 存储日志的载体不能是string，因为string每次创建都是在堆上，频繁创建和销毁，很耗费性能的，所以需要用原始的栈上数组即可。
2. 把流式操作 << 拆分成LogStream类，不要和log类耦合

查看代码 Day02
# 测试
```
int main()
{
    LOG_INFO << "hello,log";
    LOG_DEBUG << 5;
    LOG_WARN << 2.000;
    LOG_ERROR << true;
    return 0;
}
```

![](https://cdn.jsdelivr.net/gh/liukboy/PicBed@main/img/WX20231031-102601@2x.png)