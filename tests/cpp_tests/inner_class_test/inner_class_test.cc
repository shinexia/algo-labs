#include <string>
#include "glog/logging.h"
#include "gtest/gtest.h"

std::string foo_a();
std::string foo_b();

std::string foo_a_with_namespace();
std::string foo_b_with_namespace();

namespace {
const char* cstr(const std::string& str, char buf[]) {
    memcpy(buf, str.c_str(), str.size());
    buf[str.size()] = '\0';
    return buf;
}
}  // namespace

TEST(cpp_tests, TestInnerClass) {
    char buf[100];
    EXPECT_STREQ(cstr(foo_a(), buf), "from b");
    EXPECT_STREQ(cstr(foo_b(), buf), "from b");
    EXPECT_STREQ(cstr(foo_a_with_namespace(), buf), "from a with namespace");
    EXPECT_STREQ(cstr(foo_b_with_namespace(), buf), "from b with namespace");
}
