cmake_minimum_required(VERSION 3.19)
project(Example3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -pthread)

add_executable(Example3 main.c PV/head/pv.h PV/src/initsem.c PV/src/p.c PV/src/v.c)