#include "solution.h"
#include "gtest/gtest.h"

struct Case {
    char str[40];
    int expect;
};

TEST(p048, TestLongestSubstring) {
    Case cases[] = {
        {"arabcacfr", 4}, {"acfrarabc", 4}, {"arabcacfr", 4}, {"aaaa", 1},
        {"abcdefg", 7},   {"aaabbbccc", 2}, {"abcdcba", 4},   {"abcdaef", 6},
        {"a", 1},         {"", 0},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        std::string str(c.str);
        auto out = longestSubstringWithoutDuplication(str);
        EXPECT_EQ(out, c.expect) << "str: " << str;
    }
}
