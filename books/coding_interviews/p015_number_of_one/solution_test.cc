#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    int64_t num;
    int expect;
};

typedef int (*fn_type)(int);

struct FN {
    fn_type fn;
    char name[20];
};

TEST(codingInterviews, TestNumberOfOne) {
    Case cases[] = {{0, 0},           {1, 1},           {0xFFFFFFFF, 32},
                    {-1, 32},         {0x7FFFFFFF, 31}, {0x80000000, 1},
                    {-2147483648, 1}, {-2147483647, 2}};
    int N = sizeof(cases) / sizeof(Case);
    FN funcs[] = {
        {NumberOfOne, "NumberOfOne"},
        {NumberOfOne1, "NumberOfOne1"},
    };
    int K = sizeof(funcs) / sizeof(FN);
    for (int k = 0; k < K; ++k) {
        auto& fn = funcs[k];
        for (int i = 0; i < N; ++i) {
            auto& c = cases[i];
            auto out = fn.fn(c.num);
            EXPECT_EQ(out, c.expect)
                << "fn: " << std::string(fn.name) << ", num: " << c.num;
        }
    }
    EXPECT_EQ(int32_t(0x80000000), int64_t(-2147483648));
}
