#include "solution.h"
#include "gtest/gtest.h"

struct Case {
    char matrix[100];
    int rows;
    int cols;
    char str[10];
    bool expect;
};

TEST(codingInterviews, TestHasPath) {
    Case cases[] = {
        {"abtgcfcsjdeh", 4, 4, "a", true},
        {"abtgcfcsjdeh", 4, 4, "x", false},
        {"abtgcfcsjdeh", 4, 4, "bfce", true},
        {"abtgcfcsjdeh", 4, 4, "abfb", false},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto out = HasPath(c.matrix, c.rows, c.cols, c.str);
        EXPECT_EQ(out, c.expect) << "matrix: " << std::string(c.matrix)
                                 << ", str: " << std::string(c.str);
    }
}
