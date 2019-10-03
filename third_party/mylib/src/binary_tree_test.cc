#include "mylib/binary_tree.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    int preorder[20];
    int inorder[20];
    int length;
};

TEST(mylib, MakeBinaryTree) {
    mylib::Node nodes[] = {{1, 0}, {2, -1}, {4, -1}, {7, 0}, {9, 2},
                           {3, 2}, {5, -1}, {6, 1},  {8, -1}};
    int N = sizeof(nodes) / sizeof(mylib::Node);
    auto head = mylib::MakeBinaryTree(nodes, N);
    DebugPrintF(std::cout, head.get()) << std::endl;
}

TEST(mylib, CheckPreOrder) {}
