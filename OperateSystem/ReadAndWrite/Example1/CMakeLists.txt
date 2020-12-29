cmake_minimum_required(VERSION 3.19)
project(OperateSystem C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -pthread)

add_executable(OperateSystem main.c)