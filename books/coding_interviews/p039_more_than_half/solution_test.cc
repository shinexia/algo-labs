#include "solution.h"
#include "gtest/gtest.h"
#include "mylib/util.h"

struct Case {
    int numbers[20];
    int length;
    int expect;
};

typedef int (*fn_type)(int*, int);

struct FN {
    fn_type fn;
    char name[20];
};

TEST(codingInterviews, TestMoreThanHalf) {
    Case cases[] = {
        {{1, 2, 3, 2, 2, 2, 5, 4, 2}, 9, 2},
    };
    FN funcs[] = {{MoreThanHalfNum, "MoreThanHalfNum"},
                  {ImplWithPartition, "ImplWithPartition"}};
    int N = sizeof(cases) / sizeof(Case);
    int F = sizeof(funcs) / sizeof(FN);
    for (int k = 0; k < F; ++k) {
        auto& f = funcs[k];
        for (int i = 0; i < N; ++i) {
            auto& c = cases[i];
            auto out = f.fn(c.numbers, c.length);
            EXPECT_EQ(out, c.expect)
                << "fn: " << f.name
                << ", nums: " << mylib::stringify(c.numbers, c.length);
        }
    }
}
