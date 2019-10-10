#include "solution.h"
#include <cmath>
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    double base;
    int exp;
    double expect;
};

#define inf (__builtin_inf())

TEST(codingInterviews, TestPower) {
    Case cases[] = {
        {0, 0, 1},  {0.0, -10, inf}, {0.0, 10, 0}, {1, 0, 1},
        {-1, 0, 1}, {-1, 1, -1},     {-1, 2, 1},   {-2, 0, 1},
        {2, 0, 1},  {2, 1, 2},       {2, -1, 0.5}, {-2, -1, -0.5},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto out = Power(c.base, c.exp);
        EXPECT_DOUBLE_EQ(out, c.expect)
            << "base: " << c.base << ", exp: " << c.exp;
    }
}
