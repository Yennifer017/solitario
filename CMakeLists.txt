cmake_minimum_required(VERSION 3.27)
project(solitario)

set(CMAKE_CXX_STANDARD 17)

add_executable(solitario main.cpp
        Stack.cpp
        Stack.h
        Node.cpp
        Node.h
)
