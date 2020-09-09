cmake_minimum_required(VERSION 3.13)
project(Chapter03)

set(CMAKE_CXX_STANDARD 14)

include_directories(SqStack)

add_executable(Chapter03
        SqStack/SqStack.cpp
        SqStack/SqStack.h
        main.cpp LinkStack/LinkStack.h LinkStack/LinkStack.cpp SqQueue/SqQueue.h SqQueue/SqQueue.cpp LinkQueue/LinkQueue.h LinkQueue/LinkQueue.cpp)
