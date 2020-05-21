cmake_minimum_required(VERSION 3.15)
project(Interpreter)

set(CMAKE_CXX_STANDARD 14)

option(BUILD_TESTS "Build unit tests." ON)

add_subdirectory(include/catch)
add_subdirectory(src)
if (BUILD_TESTS)
    add_subdirectory(tests)
endif (BUILD_TESTS)
