project(ch01)

set(DEPS mylib gtest gtest_main)

include(../../cmake/utils.cmake)

add_simple_test(binary_search)
add_simple_test(gcd)
add_simple_test(max_subsequence_sum)
add_simple_test(pow)
