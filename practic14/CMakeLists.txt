cmake_minimum_required(VERSION 3.27)
project(practic14 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(practic14
        main.c
        stack.c
        stack.h
        students.c
        students.h)
