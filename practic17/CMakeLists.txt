cmake_minimum_required(VERSION 3.13)
project(cpractice LANGUAGES C)

set(CMAKE_C_STANDARD 11)

set(SOURCES main.c)

add_executable(cpractice WIN32 ${SOURCES})

target_link_libraries(cpractice
  comctl32
  psapi)
