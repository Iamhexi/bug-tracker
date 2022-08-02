cmake_minimum_required(VERSION 3.22.1)
project(bug-tracker)

set(CMAKE_CXX_STANDARD 20)


file(GLOB sources CONFIGURE_DEPENDS src/*.cpp)
add_executable(run ${sources} main.cpp)

find_package (SQLite3)

include_directories(${SQLite3_INCLUDE_DIRS})

target_compile_options(run PRIVATE -Wall -Wextra -pedantic)
target_link_libraries (run ${SQLite3_LIBRARIES})


# add_executable(test ${sources} tests.cpp)