#include "solution.h"
#include "gtest/gtest.h"
#include "mylib/util.h"

struct Case {
    int nums[20];
    int n;
    int expect;
};

TEST(p011, TestMin) {
    Case cases[] = {
        {{1}, 1, 1},
        {{2, 1}, 2, 1},
        {{1, 2}, 2, 1},
        {{1, 2, 3, 4, 5}, 5, 1},
        {{3, 4, 5, 1, 2}, 5, 1},
        {{1, 0, 1, 1, 1}, 5, 0},
        {{1, 1, 1, 0, 1}, 5, 0},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto out = Min(c.nums, c.n);
        EXPECT_EQ(out, c.expect)
            << "nums: " << mylib::stringify(c.nums, c.n) << ", out: " << out
            << ", expect: " << c.expect;
    }
    int empty[] = {};
    EXPECT_THROW(Min(nullptr, 0), std::exception);
    EXPECT_THROW(Min(empty, 0), std::exception);
}
