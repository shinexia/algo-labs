#include "mylib/binary_tree.h"
#include "glog/logging.h"

#include <stack>

namespace mylib {

BinaryTreeNode::~BinaryTreeNode() {
    LOG(INFO) << "btree: " << Value << " deleted";
}

void DeleteBinaryTree(BinaryTreeNode* head) {
    std::stack<BinaryTreeNode*> right_stack;
    for (; head != nullptr;) {
        auto t = head;
        if (head->Left) {
            if (head->Right) {
                // right_stack.push(head->Right);
            }
            head = head->Left;
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

deleted_unique_ptr<BinaryTreeNode> MakeBinaryTree(Node* nodes, int n) {
    deleted_unique_ptr<BinaryTreeNode> head(nullptr, DeleteBinaryTree);
    BinaryTreeNode* prev;
    std::stack<BinaryTreeNode*> stack;
    for (int i = 0; i < n; ++i) {
        auto& node = nodes[i];
        auto t = new BinaryTreeNode();
        t->Value = node.Val;
        if (i == 0) {
            head.reset(t);
        } else {
            if (node.Move < 0) {
                prev->Left = t;
            } else if (node.Move == 0) {
                prev->Right = t;
            } else {
                for (int j = 0; j < node.Move; ++j) {
                    if (stack.empty()) {
                        LOG(FATAL) << "invalid val: " << node.Val
                                   << ", move: " << node.Move;
                    }
                    stack.pop();
                }
                if (stack.empty()) {
                    LOG(FATAL) << "invalid val: " << node.Val
                               << ", move: " << node.Move;
                }
                stack.top()->Right = t;
            }
        }
        prev = t;
        stack.push(t);
    }
    return head;
}

static int _DebugPrintF(std::ostream& os, BinaryTreeNode* head, int depth) {
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

}  // namespace mylib
