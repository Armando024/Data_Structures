cmake_minimum_required(VERSION 3.5)
project(homework5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stack.h stack.template stack_list.h stack_list.template list_array.h list_array.template)
add_executable(homework5 ${SOURCE_FILES})