#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    int preorder[20];
    int inorder[20];
    int length;
};

TEST(p007, TestConstruct) {
    Case cases[] = {
        {{1, 2, 4, 7, 3, 5, 6, 8}, {4, 7, 2, 1, 5, 3, 8, 6}, 8},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto head = Construct(c.preorder, c.inorder, c.length);
        PrintTreeF(std::cout, head) << std::endl;
        EXPECT_TRUE(CheckPreOrder(head, c.preorder, c.length));
        EXPECT_TRUE(CheckInOrder(head, c.inorder, c.length));
        DeleteBinaryTree(head);
    }
}
