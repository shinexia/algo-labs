cmake_minimum_required(VERSION 3.0)
project(algorithm_labs)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

set(GTEST_ROOT_DIR third_party/gtest/googletest)
set(GLOG_ROOT_DIR third_party/glog)
set(MYLIB_ROOT_DIR mylib)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Valgrind REQUIRED)

set(TEST_DEPS
    glog::glog
    gtest
    mylib
    mytest_main)

# turn off glog test targets
set(BUILD_TESTING OFF)

include(cmake/macros.cmake)

# thirdparty
include_directories(${GTEST_ROOT_DIR}/include)
add_subdirectory(${GTEST_ROOT_DIR})

include_directories(${CMAKE_BINARY_DIR}/${GLOG_ROOT_DIR})
include_directories(${GLOG_ROOT_DIR}/src)
add_subdirectory(${GLOG_ROOT_DIR})

# mylib
include_directories(${MYLIB_ROOT_DIR}/include)
add_subdirectory(${MYLIB_ROOT_DIR})

# sub projects
add_subdirectory(books/data_structure_and_algorithm_analysis)
add_subdirectory(books/coding_interviews)
add_subdirectory(leetcode)

add_subdirectory(tests)
