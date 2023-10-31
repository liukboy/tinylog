cmake_minimum_required(VERSION 3.12)  # 指定CMake最低版本
project(tinylog)  # 指定项目名称

# 设置C++标准，可以根据需要更改
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
#add_executable(tinylog main.cpp)  # 将main.cpp替换为您的源文件

# 添加其他依赖项（如库文件、头文件等）
# find_package() 和 target_link_libraries() 等命令用于添加依赖项

# 添加可选的编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -pthread")

# 设置输出目录
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 安装规则，用于安装可执行文件和其他文件
# install(TARGETS YourExecutableName DESTINATION bin)

# 可以根据需要添加更多自定义设置和配置

# 添加子目录
add_subdirectory(test)  # 替换为您的子目录名称