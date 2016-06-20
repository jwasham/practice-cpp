cmake_minimum_required(VERSION 3.5)
project(queue_llist_lib)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_GLIBCXX_DEBUG")

set(HEADER_FILES queue_linked_list.h)

set(SOURCE_FILES queue_linked_list.cc)

add_library(queue_llist_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
