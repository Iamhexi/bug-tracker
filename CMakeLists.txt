cmake_minimum_required(VERSION 3.22.1)
project(bug-tracker)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sources CONFIGURE_DEPENDS src/*.cpp)

add_executable(run ${sources} main.cpp)
# add_executable(test ${sources} tests.cpp)