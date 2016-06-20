cmake_minimum_required(VERSION 3.5)
project(queue_llist_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cc)
add_executable(queue_llist_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(queue_llist_run queue_llist_lib)
