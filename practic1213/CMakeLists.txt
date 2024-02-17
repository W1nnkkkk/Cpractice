cmake_minimum_required(VERSION 3.27)
project(practice13C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(practice13C
        main.c
        stack.c
        stack.h
        students.c
        students.h)
