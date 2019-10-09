#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    int number;
    int expect;
};

TEST(p046, TestGetTranslationCount) {
    Case cases[] = {
        {-100, 0}, {0, 1},   {9, 1},   {10, 2},  {25, 2},    {26, 1},  {99, 1},
        {100, 2},  {110, 3}, {125, 3}, {126, 2}, {12258, 5}, {426, 1},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto out = GetTranslationCount(c.number);
        EXPECT_EQ(out, c.expect) << "number: " << c.number;
    }
}
