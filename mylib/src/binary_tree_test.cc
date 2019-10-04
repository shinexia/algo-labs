#include "mylib/binary_tree.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

using namespace mylib;

struct Case {
    int preorder[20];
    int inorder[20];
    int length;
};

TEST(mylib, MakeBinaryTree) {
    CVal nodes[] = {{1, 0}, {2, -1}, {4, -1}, {7, 0}, {9, 2},
                    {3, 2}, {5, -1}, {6, 1},  {8, -1}};
    int preorders[] = {1, 2, 4, 7, 9, 3, 5, 6, 8};
    int inorders[] = {4, 7, 2, 9, 1, 5, 3, 8, 6};
    int post_orders[] = {7, 4, 9, 2, 5, 8, 6, 3, 1};

    int N = sizeof(nodes) / sizeof(mylib::CVal);
    auto head = mylib::MakeBinaryTree(nodes, N);
    PrintTreeF(std::cout, head.get()) << std::endl;

    EXPECT_TRUE(CheckPreOrder(head.get(), preorders, N));
    EXPECT_TRUE(CheckInOrder(head.get(), inorders, N));
    EXPECT_TRUE(CheckPostOrder(head.get(), post_orders, N));
}
