#include "mylib/qsort.h"
#include "gtest/gtest.h"
#include "mylib/util.h"

struct Case {
    int a[50];
    int len;
    int expect[50];
};

bool arrayEqual(int* a, int* b, int len) {
    for (int i = 0; i < len; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

TEST(mylib, TestQsort) {
    Case cases[] = {
        {{}, 0, {}},
        {{1}, 1, {1}},
        {{1, 2}, 2, {1, 2}},
        {{2, 1, 3}, 3, {1, 2, 3}},
        {{2, -1, -3}, 3, {-3, -1, 2}},
        {{3, 5, 4}, 3, {3, 4, 5}},
        {{3, 5, 4, 3}, 4, {3, 3, 4, 5}},
        {{5, 3, 8, 6, 4}, 5, {3, 4, 5, 6, 8}},
        {{6, 1, 2, 7, 9, 3, 4, 5, 10, 8}, 10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}},
        {{6, 5, 3, 1, 8, 7, 2, 4}, 8, {1, 2, 3, 4, 5, 6, 7, 8}},
        {{13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10},
         16,
         {10, 13, 14, 23, 25, 25, 27, 33, 39, 45, 59, 65, 73, 82, 94, 94}},
        {{3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7,
          0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6},
         30,
         {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
          5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9}},
        {{16, 4, 10, 14, 7, 9, 3, 2, 8, 1},
         10,
         {1, 2, 3, 4, 7, 8, 9, 10, 14, 16}},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        mylib::QuikSort(c.a, c.len);
        EXPECT_TRUE(arrayEqual(c.a, c.expect, c.len))
            << "out: " << mylib::stringify(c.a, c.len) << ", expect: " << mylib::stringify(c.expect, c.len);
    }
}
