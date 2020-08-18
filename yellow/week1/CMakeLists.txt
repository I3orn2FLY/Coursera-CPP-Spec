cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(TARGET_NAME "week1")
project(${TARGET_NAME})
add_executable(${TARGET_NAME} main.cpp)
target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)


