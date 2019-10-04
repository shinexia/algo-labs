cmake_minimum_required(VERSION 3.0)
project(algorithm_labs)

set(CMAKE_CXX_STANDARD 11)

add_compile_options("-g")

set(GTEST_ROOT_DIR thirdparty/gtest/googletest)
set(GLOG_ROOT_DIR thirdparty/glog)
set(MYLIB_ROOT_DIR mylib)

set(TEST_DEPS
    glog::glog
    gtest
    mylib
    mytest_main)

# Valgrind (memcheck): ctest -D ExperimentalMemCheck
find_program(VALGRIND_EXECUTABLE NAMES valgrind)
if(VALGRIND_EXECUTABLE)
  # Use BIG output sizes to avoid truncation.
  set(CTEST_CUSTOM_MAXIMUM_PASSED_TEST_OUTPUT_SIZE 1024000)
  set(CTEST_CUSTOM_MAXIMUM_FAILED_TEST_OUTPUT_SIZE 10240000)

  set(CTEST_MEMORYCHECK_COMMAND ${VALGRIND_EXECUTABLE})

  set(
    CTEST_MEMORYCHECK_COMMAND_OPTIONS
    "-v --tool=memcheck --leak-check=full --trace-children=yes --track-origins=yes "
    )
else()
  message(STATUS "WARNING: valgrind executable not found.")
  message(STATUS "Try: sudo apt install valgrind")
endif()

enable_testing()

include(CTest)

# turn off glog test targets
set(BUILD_TESTING OFF)

# macros
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
