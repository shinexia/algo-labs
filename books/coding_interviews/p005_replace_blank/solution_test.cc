#include "solution.h"
#include "gtest/gtest.h"

#define LENGTH 40

struct Case {
    char str[LENGTH];
    char expect[LENGTH];
};

TEST(codingInterviews, TestReplaceBlank) {
    Case cases[] = {
        {"hello world  ", "hello%20world%20%20"},
        {"", ""},
        {" ", "%20"},
        {"hello", "hello"},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto retCode = ReplaceBlank(c.str, LENGTH);
        EXPECT_EQ(strcmp(c.str, c.expect), 0);
    }
}
