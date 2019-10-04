#include "solution.h"

BinaryTreeNode* GetNext(BinaryTreeNode* node) {
    if (node == nullptr) {
        return node;
    }
    if (node->Right != nullptr) {
        // 右节点的最左节点
        node = node->Right;
        while (node->Left != nullptr) {
            node = node->Left;
        }
        return node;
    } else {
        // 回溯父节点，找第一个node为其的左节点的parent，可能为nullptr
        auto parent = node->Parent;
        while (parent != nullptr && parent->Right == node) {
            node = parent;
            parent = parent->Parent;
        }
        return parent;
    }
}
