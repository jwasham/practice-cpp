cmake_minimum_required(VERSION 3.5)
project(quick_sort_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES
        main.cc
        test_sort.cc
        quick_sort.cc
        )

add_executable(quick_sort ${SOURCE_FILES} ${HEADER_FILES})
