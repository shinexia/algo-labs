#include "binary_search.h"

#include "mylib/mylib.h"
#include "gtest/gtest.h"

struct Case {
    ElementType A[10];
    int N;
    ElementType x;
    int expect;
};

TEST(TestBinarySearch, simple) {
    Case cases[] = {{{},                          0, 1,  NotFound},
                    {{1},                         1, 1,  0},
                    {{1},                         1, -1, NotFound},
                    {{1},                         1, 2,  NotFound},
                    {{1,  2},                     2, -1, NotFound},
                    {{1,  2},                     2, 3,  NotFound},
                    {{1,  2},                     2, 1,  0},
                    {{1,  2},                     2, 2,  1},
                    {{-3, -2, -1, 0, 1, 2, 3, 4}, 8, -1, 2},
                    {{-3, -2, -1, 0, 1, 2, 3, 4}, 8, 1,  4}};

    int N = sizeof(cases) / sizeof(Case);

    for (int i = 0; i < N; i++) {
        const Case *c = &(cases[i]);
        EXPECT_EQ(c->expect, BinarySearch(c->A, c->x, c->N))
                            << mylib::stringify(c->A, c->N);
    }
}
