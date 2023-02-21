cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(comp)

# 编译增加子目录
add_subdirectory(src)

# 编译选项
# -g 生成调试信息。GNU调试器可利用该信息
# -O0 不进行优化处理
# -O1 -O2 -O3 编译器优化程序
# -Wall 生成所有警告信息
# add_compile_definitions("-Wall -g -O0 -Werror")
# add_compile_options("-Wall -g -O0 -Werror")

SET(CMAKE_BUILD_TYPE "Debug")

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -O0 -Werror")

SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")