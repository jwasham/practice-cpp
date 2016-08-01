cmake_minimum_required(VERSION 3.5)
project(graphse_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES
        main.cc
        Graph.cc
        GraphRepresentation.cc
        DirectedGraph.cc
        )

add_executable(graphs ${SOURCE_FILES} ${HEADER_FILES})
