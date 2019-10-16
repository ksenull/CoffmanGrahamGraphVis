cmake_minimum_required(VERSION 3.10)
project(CoffmanGraham)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${INCLUDE_DIRS})

add_executable(CoffmanGraham main.cpp CoffmanGrahamAlgorithm.h Graph.h CoffmanGrahamAlgorithm.cpp NamedType.h Graph.cpp)