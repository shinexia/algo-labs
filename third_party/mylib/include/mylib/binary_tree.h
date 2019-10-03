#ifndef MYLIB_BINARY_TREE_H
#define MYLIB_BINARY_TREE_H

#include <ostream>
#include "mylib/mylib.h"

namespace mylib {

struct BinaryTreeNode {
    int Value;
    BinaryTreeNode* Left = nullptr;
    BinaryTreeNode* Right = nullptr;
    ~BinaryTreeNode();
};

struct Node {
    int Val;
    int Move;
};

void DeleteBinaryTree(BinaryTreeNode* head);
deleted_unique_ptr<BinaryTreeNode> MakeBinaryTree(Node* nodes, int n);
std::ostream& DebugPrintF(std::ostream& os, BinaryTreeNode* head);
bool CheckPreOrder(BinaryTreeNode* head, int* values, int length);

}  // namespace mylib

#endif  // MYLIB_BINARY_TREE_H
