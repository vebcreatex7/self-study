cmake_minimum_required(VERSION 3.16.3)

project(prog)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")
add_executable(prog main.cpp foo.cpp bar.cpp zoo.cpp)