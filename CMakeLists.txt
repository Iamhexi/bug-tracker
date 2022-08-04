
cmake_minimum_required(VERSION 3.22.1)
project(bug-tracker)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

# creates variables containing lists of files
file(GLOB sources CONFIGURE_DEPENDS src/*.cpp)
file(GLOB tests CONFIGURE_DEPENDS test/*.cpp)

# creating executables
add_executable(run ${sources} main.cpp)
add_executable(test ${sources} ${tests} test/test.cpp)

# finding packages
find_package(SQLite3)
find_package(GTest REQUIRED)

# including directories
include_directories(${SQLite3_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

# run target
target_compile_options(run PRIVATE -Wall -Wextra -pedantic)
target_link_libraries (run ${SQLite3_LIBRARIES} fmt::fmt)

# test target
target_compile_options(test PRIVATE -Wall -Wextra -pedantic)
target_link_libraries (test ${SQLite3_LIBRARIES} ${GTEST_LIBRARIES} fmt::fmt)