cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp SqList/SqList.h SqList/SqList.cpp LinkList/LinkList.cpp LinkList/LinkList.h)