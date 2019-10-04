#include "pow.h"

#include "gtest/gtest.h"
#include "mylib/mylib.h"

struct Case {
    ElementType X;
    int n;
    ElementType expect;
};

typedef ElementType (*fn_pow)(ElementType X, int n);

struct FN {
    fn_pow fn;
    const char *name;
};

TEST(TestPow, simple) {
    Case cases[] = {{0, 0, 1},  // special case
                    {0, 1, 0},  {0, 10, 0}, {1, 0, 1},     {1, 1, 1},
                    {1, 10, 1}, {2, 0, 1},  {2, 1, 2},     {2, 10, 1024},
                    {3, 0, 1},  {3, 1, 3},  {3, 10, 59049}};

    FN funcs[] = {{Pow, "Pow"}};

    int N = sizeof(cases) / sizeof(Case);
    int K = sizeof(funcs) / sizeof(FN);

    for (int j = 0; j < K; j++) {
        FN *f = &(funcs[j]);
        for (int i = 0; i < N; i++) {
            Case *c = &(cases[i]);
            EXPECT_EQ(f->fn(c->X, c->n), c->expect)
                << "fn=" << f->name << ", X=" << c->X << ", n=" << c->n;
        }
    }
}
