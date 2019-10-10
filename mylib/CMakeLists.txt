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

add_library(mylib STATIC ${mylib_headers} ${mylib_sources})
add_library(mytest_main STATIC src/mytest_main.cc)
target_link_libraries(mylib glog gtest)

add_test_cc(ostream_op_test src/ostream_op_test.cc)
add_test_cc(util_test src/util_test.cc)
add_test_cc(binary_tree_test src/binary_tree_test.cc)
add_test_cc(algo_test src/algo_test.cc)
add_test_cc(qsort_test src/qsort_test.cc)
