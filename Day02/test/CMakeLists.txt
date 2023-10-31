aux_source_directory(${CMAKE_SOURCE_DIR} SRC_LIST)
include_directories(../)

MESSAGE(STATUS "src list:${SRC_LIST}.")

aux_source_directory(${CMAKE_SOURCE_DIR}/test TEST_SRC_LIST)

foreach(SOURCE ${TEST_SRC_LIST})
    get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE} ${SRC_LIST})  # 将main.cpp替换为您的源文件
endforeach()
# 添加可执行文件

# 添加其他依赖项（如库文件、头文件等）
# find_package() 和 target_link_libraries() 等命令用于添加依赖项

# 添加可选的编译选项
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# 设置输出目录
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 安装规则，用于安装可执行文件和其他文件
# install(TARGETS YourExecutableName DESTINATION bin)

# 可以根据需要添加更多自定义设置和配置
