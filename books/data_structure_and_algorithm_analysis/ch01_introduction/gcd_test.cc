#include "gcd.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    ElementType M;
    ElementType N;
    ElementType expect;
};

typedef ElementType (*fn_gcd)(ElementType M, ElementType N);

struct FN {
    fn_gcd fn;
    const char *name;
};

TEST(TestGcd, simple) {
    Case cases[] = {{0, 0, 0}, {0, 1, 1}, {1, 0, 1},  {1, 1, 1},
                    {2, 3, 1}, {2, 4, 2}, {12, 8, 4}, {8, 12, 4}};
    FN funcs[] = {{GCD, "GCD"}};

    int N = sizeof(cases) / sizeof(Case);
    int K = sizeof(funcs) / sizeof(FN);

    for (int j = 0; j < K; j++) {
        FN *f = &(funcs[j]);
        for (int i = 0; i < N; i++) {
            Case *c = &(cases[i]);
            EXPECT_EQ(f->fn(c->M, c->N), c->expect)
                << "fn=" << f->name << ", M=" << c->M << ", N=" << c->N;
        }
    }
}
