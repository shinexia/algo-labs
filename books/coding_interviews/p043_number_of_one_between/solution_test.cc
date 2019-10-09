#include "solution.h"
#include <cmath>
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    int n;
    int expect;
};

TEST(p043, TestLessThan) {
    Case cases[] = {
        {1, 0},     {10, 1},     {20, 12},     {90, 19},        {100, 20},
        {200, 140}, {1000, 300}, {2000, 1600}, {100000, 50000},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        int num = c.n, base = 1, exp = 0;
        while (num >= 10) {
            num /= 10;
            base *= 10;
            ++exp;
        }
        int out = lessThan(num, base, exp);
        int real = simple(c.n - 1);
        EXPECT_TRUE(out == c.expect && out == real)
            << "n:" << c.n << ", num:" << num << ", base:" << base
            << ", exp:" << exp << ", real:" << real << ", out:" << out
            << ", expect:" << c.expect;
    }
}

TEST(p043, TestNumberOfOneBetween) {
    int real = 0;
    for (int i = 0; i < 100000; ++i) {
        real += NumberOfOne(i);
        auto out = NumberOfOneBetween(i);
        EXPECT_EQ(out, real) << "i:" << i;
        if (out != real) {
            break;
        }
    }
}
