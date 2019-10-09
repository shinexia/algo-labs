#include <string>
#include "glog/logging.h"
#include "gtest/gtest.h"

std::string foo_a();
std::string foo_b();

std::string foo_a_with_namespace();
std::string foo_b_with_namespace();

TEST(cpp_tests, TestInnerClass) {
    LOG(INFO) << "a: " << foo_a();                                // from b, 依赖于a.cc和b.cc哪个在前
    LOG(INFO) << "b: " << foo_b();                                // from b
    LOG(INFO) << "a with namespace: " << foo_a_with_namespace();  // from a
    LOG(INFO) << "b with namespace: " << foo_b_with_namespace();  // from b
}
