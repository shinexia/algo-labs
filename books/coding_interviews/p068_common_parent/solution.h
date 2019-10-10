#pragma once

#include "mylib/binary_tree.h"

using namespace mylib;

BinaryTreeNode* GetLastCommonParent(BinaryTreeNode* root, BinaryTreeNode* node1,
                                    BinaryTreeNode* node2);

BinaryTreeNode* GetLastCommonParent_WithParentPointer(BinaryTreeNode* root,
                                                      BinaryTreeNode* node1,
                                                      BinaryTreeNode* node2);

BinaryTreeNode* GetLastCommonParent_WithBST(BinaryTreeNode* root,
                                            BinaryTreeNode* node1,
                                            BinaryTreeNode* node2);