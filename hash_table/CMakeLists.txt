cmake_minimum_required(VERSION 3.5)
project(hash_table_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(HEADER_FILES hash_table.h hash_tables_tests.h)

set(SOURCE_FILES main.cc hash_table.cc hash_tables_tests.cc)

add_executable(hash_table ${SOURCE_FILES} ${HEADER_FILES})
