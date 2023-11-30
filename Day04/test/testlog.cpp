#include <memory>
#include <chrono>
#include <iostream>

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
    auto now = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; ++i)
    {
        LOG_INFO << "Hello 12312313";
    }
    auto end = std::chrono::steady_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - now);
    std::cout << "write 1000000 notes, spend: " << t.count() << "ms" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}