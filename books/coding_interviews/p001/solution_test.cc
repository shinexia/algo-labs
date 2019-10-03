#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"
#include "mylib/mylib.h"

TEST(p001, CMyString) {
    const char hello[] = "hello";
    const CMyString str1(hello);
    CMyString str2 = "world";
    CMyString str3;
    CMyString str4 = str3 = str1;
    CMyString str5 = std::move(str4);
    EXPECT_TRUE(str1 == (const char*)hello);
    EXPECT_TRUE(str2 == "world");
    EXPECT_TRUE(str3 == str1);
    EXPECT_TRUE(str4 == nullptr);
    EXPECT_TRUE(str5 == str1);
    EXPECT_TRUE(str5 != str2);
}
