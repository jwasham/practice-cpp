cmake_minimum_required(VERSION 3.5)
project(linked_list_lib)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_GLIBCXX_DEBUG")

set(HEADER_FILES
        linked_list.h

        )

set(SOURCE_FILES
        linked_list.cc
        )

add_library(linked_list_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
