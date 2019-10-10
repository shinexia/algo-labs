#include "solution.h"
#include "gtest/gtest.h"
#include "mylib/util.h"

struct Case {
    int matrix[64];
    int rows;
    int columns;
    int number;
    bool expect;
};

TEST(codingInterviews, TestFind) {
    Case cases[] = {
        {{1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15}, 4, 4, 7, true},
        {{1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15}, 4, 4, 5, false},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto out = Find(c.matrix, c.rows, c.columns, c.number);
        EXPECT_EQ(out, c.expect)
            << mylib::stringify(c.matrix, c.rows * c.columns)
            << ", number:" << c.number;
    }
}
