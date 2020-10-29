cmake_minimum_required(VERSION 3.13)
project(Chapter05)

set(CMAKE_CXX_STANDARD 14)
#target_sources(main.cpp  BTree/BTree.cpp BTree/BTree.h ThreadBTree/TBTree.cpp ThreadBTree/TBTree.h)

add_executable(${PROJECT_NAME} main.cpp BTree/BTree.cpp BTree/BTree.h ThreadBTree/TBTree.cpp ThreadBTree/TBTree.h)