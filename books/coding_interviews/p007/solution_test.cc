#include "solution.h"
#include "gtest/gtest.h"

struct Case {
    int preorder[20];
    int inorder[20];
    int length;
};

TEST(p007, MakeBinaryTree) {
    Node nodes[] = {{1, 0}, {2, -1}, {4, -1}, {7, 0},  //{5, 2},
                    {3, 3}, {5, -1}, {6, 1},  {8, -1}};
    int N = sizeof(nodes) / sizeof(Node);
    BinaryTreeNode* head = MakeBinaryTree(nodes, N);
    DebugPrintF(std::cout, head) << std::endl;
    DeleteBinaryTree(head);
}

TEST(p007, CheckPreOrder) {
    Node nodes[] = {{1, 0}, {2, -1}, {4, -1}, {7, 0},  //{5, 2},
                    {3, 3}, {5, -1}, {6, 1},  {8, -1}};
    int N = sizeof(nodes) / sizeof(Node);
    BinaryTreeNode* head = MakeBinaryTree(nodes, N);
}