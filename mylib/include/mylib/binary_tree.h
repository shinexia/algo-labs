#ifndef MYLIB_BINARY_TREE_H
#define MYLIB_BINARY_TREE_H

#pragma once
#include <ostream>
#include "mylib/util.h"

namespace mylib {

struct BinaryTreeNode {
    int Value;
    BinaryTreeNode* Parent = nullptr;
    BinaryTreeNode* Left = nullptr;
    BinaryTreeNode* Right = nullptr;
    BinaryTreeNode() : Value(0) {}
    BinaryTreeNode(int val) : Value(val) {}
    ~BinaryTreeNode();

    BinaryTreeNode* SetLeft(BinaryTreeNode* left);
    BinaryTreeNode* SetRight(BinaryTreeNode* right);
    BinaryTreeNode* RemoveChild(BinaryTreeNode* child);
    BinaryTreeNode* SetParent(BinaryTreeNode* right);
};

// 用于创建二叉树，-1：左节点，0：有节点，n: 向上回溯n个节点
struct CVal {
    int Val;
    int Move;
};

deleted_unique_ptr<BinaryTreeNode> MakeUnique(BinaryTreeNode* head);
void DeleteBinaryTree(BinaryTreeNode* head);

deleted_unique_ptr<BinaryTreeNode> MakeBinaryTree(CVal* vals, int num_vals);

std::ostream& PrintTreeF(std::ostream& os, BinaryTreeNode* head);
std::ostream& PrintNodeF(std::ostream& os, BinaryTreeNode* head);

std::string PrintTree(BinaryTreeNode* head);
std::string PrintNode(BinaryTreeNode* head);

// 检查前序遍历
bool CheckPreOrder(BinaryTreeNode* head, int* preorders, int num_orders);

// 检查中序遍历
bool CheckInOrder(BinaryTreeNode* head, int* inorders, int num_orders);

// 检查后序遍历
bool CheckPostOrder(BinaryTreeNode* head, int* postorders, int num_orders);

// 获取指定节点，-1: 往左走一步，1: 往右走一步，0或者结束: 返回当前节点
BinaryTreeNode* GetFromPath(BinaryTreeNode* head, int* path, int num_path);

}  // namespace mylib

#endif  // MYLIB_BINARY_TREE_H
