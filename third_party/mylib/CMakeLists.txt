include(../../cmake/macros.cmake)

set(TEST_DEPS
    glog::glog
    gtest
    mylib
    gtest_main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB mylib_headers "include/mylib/*.h")
file(GLOB mylib_sources "src/*.cc")
list(FILTER
     mylib_sources
     EXCLUDE
     REGEX
     ".*_test.cc$")

list(FILTER
     mylib_sources
     EXCLUDE
     REGEX
     ".*_main.cc$")

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC ${CMAKE_CXX_FLAGS}")

add_library(mylib SHARED ${mylib_headers} ${mylib_sources})
add_library(mytest_main STATIC "src/mytest_main.cc")

add_test_cc(binary_tree_test src/binary_tree_test.cc)
