cmake_minimum_required(VERSION 3.0)
project(algorithm_labs)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_ROOT_DIR third_party/gtest/googletest)
set(GLOG_ROOT_DIR third_party/glog)
set(MYLIB_ROOT_DIR third_party/mylib)

add_subdirectory(${GTEST_ROOT_DIR})
include_directories(${GTEST_ROOT_DIR}/include)

add_subdirectory(${GLOG_ROOT_DIR})
include_directories(${GLOG_ROOT_DIR}/src)

add_subdirectory(${MYLIB_ROOT_DIR})
include_directories(${MYLIB_ROOT_DIR}/include)

add_subdirectory(books/data_structure_and_algorithm_analysis)
add_subdirectory(books/coding_interviews)
add_subdirectory(leetcode)

add_subdirectory(tests)
