cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(TARGET_NAME "week6")
project(${TARGET_NAME})

file(GLOB SRC "*.cpp")
add_executable(${TARGET_NAME} ${SRC})
#target_compile_options(${TARGET_NAME})


