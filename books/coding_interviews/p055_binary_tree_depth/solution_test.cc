#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    CVal vals[10];
    int len;
    int expect;
};

TEST(p055, TestTreeDepth) {
    Case cases[] = {
        {{{}}, 0, 0},
        {{{1, 0}}, 1, 1},
        {{{1, 0}, {2, -1}}, 2, 2},
        {{{1, 0}, {3, 0}}, 2, 2},
        {{{1, 0}, {2, -1}, {3, 1}}, 3, 2},
        {{{1, 0}, {2, -1}, {4, -1}, {7, 0}, {5, 2}, {3, 2}, {6, 0}}, 7, 4},
        {{{1, 0},
          {2, -1},
          {4, -1},
          {7, 0},
          {9, 2},
          {3, 2},
          {5, -1},
          {6, 1},
          {8, -1}},
         9,
         4},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 5; i < N; ++i) {
        auto& c = cases[i];
        auto head = MakeBinaryTree(c.vals, c.len);
        EXPECT_EQ(TreeDepth(head.get()), c.expect) << "tree:\n"
                                                   << PrintTree(head.get());
    }
}
