cmake_minimum_required(VERSION 3.29)
project(test_final)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_final main.cpp
        Node.cpp
        Node.h
        LinkedList.cpp
        LinkedList.h
        Database.cpp
        Database.h
        Utils.cpp
        Utils.h)
