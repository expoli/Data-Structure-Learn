cmake_minimum_required(VERSION 3.13)
PROJECT(Chapter02)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp SqList/SqList.cpp SqList/SqList.h DLinkList/DLinkList.cpp DLinkList/DLinkList.h LinkList/LinkList.cpp LinkList/LinkList.h)
TARGET_LINK_LIBRARIES(${PROJECT_NAME})