cmake_minimum_required(VERSION 3.5)
project(homework6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp priority_queue.h)
add_executable(homework6 ${SOURCE_FILES})