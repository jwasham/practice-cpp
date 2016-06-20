cmake_minimum_required(VERSION 3.5)
project(queue_array_lib)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_GLIBCXX_DEBUG")

set(HEADER_FILES queue_array.h)

set(SOURCE_FILES queue_array.cc)

add_library(queue_array_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
