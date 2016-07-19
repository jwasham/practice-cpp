cmake_minimum_required(VERSION 3.5)
project(merge_sort_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cc)

add_executable(merge_sort ${SOURCE_FILES} ${HEADER_FILES})
