cmake_minimum_required(VERSION 3.5)
project(homework4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sequence.h sequence.template)
add_executable(homework4 ${SOURCE_FILES})