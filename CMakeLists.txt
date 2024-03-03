cmake_minimum_required(VERSION 3.27)
project(cpractice C)

set(CMAKE_C_STANDARD 11)

include_directories(practic14)

add_executable(cpractice
        practic14/main.c
        practic14/stack.c
        practic14/stack.h
        practic14/students.c
        practic14/students.h)
