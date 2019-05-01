cmake_minimum_required(VERSION 3.0)
project(algorithm_labs)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_ROOT_DIR third_party/gtest/googletest)
set(MYLIB_ROOT_DIR third_party/mylib)

add_subdirectory(${GTEST_ROOT_DIR})
include_directories(${GTEST_ROOT_DIR}/include)

add_subdirectory(${MYLIB_ROOT_DIR})
include_directories(${MYLIB_ROOT_DIR}/include)


add_subdirectory(book_data_structure_and_algorithm_analysis)
add_subdirectory(leetcode)

add_subdirectory(tests/cpp_tests)
