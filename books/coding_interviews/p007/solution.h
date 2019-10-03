#ifndef P007_SOLUTION_H
#define P007_SOLUTION_H

#include <algorithm>
#include <functional>
#include <memory>
#include <ostream>
#include <stack>
#include <vector>

struct BinaryTreeNode {
    int Value;
    BinaryTreeNode* Left = nullptr;
    BinaryTreeNode* Right = nullptr;
};

struct Node {
    int Val;
    int Move;
};

void DeleteBinaryTree(BinaryTreeNode* head) {
    std::stack<BinaryTreeNode*> right_stack;
    for (; head != nullptr;) {
        auto t = head;
        if (head->Left) {
            head = head->Left;
            if (head->Right) {
                right_stack.push(head->Right);
            }
        } else if (head->Right) {
            head = head->Right;
        } else if (!right_stack.empty()) {
            head = right_stack.top();
            right_stack.pop();
        } else {
            head = nullptr;
        }
        delete t;
    }
    return;
}

template <typename T>
using deleted_unique_ptr = std::unique_ptr<T, std::function<void(T*)>>;

deleted_unique_ptr<BinaryTreeNode> make_unique(BinaryTreeNode* head) {
    return deleted_unique_ptr<BinaryTreeNode>(head, DeleteBinaryTree);
}

BinaryTreeNode* MakeBinaryTree(Node* nodes, int n) {
    BinaryTreeNode *head, *prev;
    std::stack<BinaryTreeNode*> stack;
    for (int i = 0; i < n; ++i) {
        auto& node = nodes[i];
        auto t = new BinaryTreeNode();
        t->Value = node.Val;
        if (i == 0) {
            head = t;
        } else {
            if (node.Move < 0) {
                prev->Left = t;
            } else if (node.Move == 0) {
                prev->Right = t;
            } else {
                for (int j = 0; j < node.Move; ++j) {
                    stack.pop();
                }
                stack.top()->Right = t;
                stack.pop();
            }
        }
        prev = t;
        stack.push(t);
    }
    return head;
}

int _DebugPrintF(std::ostream& os, BinaryTreeNode* head, int depth) {
    if (head->Right) {
        _DebugPrintF(os, head->Right, depth + 1);
        os << "\n";
    }
    for (int i = 0; i < depth; ++i) {
        os << "  ";
    }
    os << head->Value;
    if (head->Left) {
        os << "\n";
        _DebugPrintF(os, head->Left, depth + 1);
    }
    return 0;
}

std::ostream& DebugPrintF(std::ostream& os, BinaryTreeNode* head) {
    if (head != nullptr) {
        _DebugPrintF(os, head, 0);
    } else {
        os << "<nil>";
    }
    return os;
}

bool CheckPreOrder(BinaryTreeNode* head, int* values, int length) {
    if (head == nullptr) {
        return length == 0;
    }
    std::stack<BinaryTreeNode*> stack;
    int i = 0;
    while (true) {
        if (i >= length) {
            return head == nullptr;
        }
        int val = values[i++];
        if (val != head->Value) {
            return false;
        }
        if (head->Right != nullptr) {
            stack.push(head->Right);
        }
        if (head->Left != nullptr) {
            head = head->Left;
        } else if (!stack.empty()) {
            head = stack.top();
            stack.pop();
        } else {
            return i == length;
        }
    }
    return true;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {}

#endif  // P007_SOLUTION_H
