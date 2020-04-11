#ifndef MYLIB_BINARY_TREE_H
#define MYLIB_BINARY_TREE_H

#pragma once
#include <ostream>
#include "mylib/util.h"

namespace mylib {

#define NULL_INT int32_t(0x80000000)
#define NULL_INT_NAME "NULL"

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

std::vector<std::string> Serialize(const BinaryTreeNode* root);
deleted_unique_ptr<BinaryTreeNode> Deserialize(const int* vals, int num_val);
deleted_unique_ptr<BinaryTreeNode> Deserialize(const std::vector<int>& vals);

deleted_unique_ptr<BinaryTreeNode> MakeBinaryTree(const CVal* vals,
                                                  int num_vals);
deleted_unique_ptr<BinaryTreeNode> MakeBinarySearchTree(const int vals[],
                                                        int num_val);

std::ostream& PrintTreeF(std::ostream& os, const BinaryTreeNode* head);
std::ostream& PrintNodeF(std::ostream& os, const BinaryTreeNode* head);

std::string PrintTree(const BinaryTreeNode* head);
std::string PrintNode(const BinaryTreeNode* head);

// 检查前序遍历
bool CheckPreOrder(const BinaryTreeNode* head, const int* preorders,
                   int num_orders);

// 检查中序遍历
bool CheckInOrder(const BinaryTreeNode* head, const int* inorders,
                  int num_orders);

// 检查后序遍历
bool CheckPostOrder(const BinaryTreeNode* head, const int* postorders,
                    int num_orders);

// 获取指定节点，-1: 往左走一步，1: 往右走一步，0或者结束: 返回当前节点
BinaryTreeNode* GetFromPath(BinaryTreeNode* head, const int* path,
                            int num_path);

}  // namespace mylib

#endif  // MYLIB_BINARY_TREE_H
