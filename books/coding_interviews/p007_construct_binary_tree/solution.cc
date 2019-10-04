#include "solution.h"
#include <stack>
#include "glog/logging.h"

int findPosition(int* order, int start, int end, int val) {
    for (int i = start; i < end; ++i) {
        if (order[i] == val) {
            return i;
        }
    }
    return -1;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    if (preorder == nullptr || inorder == nullptr || length <= 0) {
        return nullptr;
    }
    deleted_unique_ptr<BinaryTreeNode> root(new BinaryTreeNode(preorder[0]),
                                            DeleteBinaryTree);
    if (length > 1) {
        int start = 0, end = length;
        int mid = findPosition(inorder, start, end, root->Value);
        BinaryTreeNode* prev = root.get();
        std::stack<std::pair<BinaryTreeNode*, int>> stack;
        stack.emplace(prev, mid);
        for (int i = 1; i < length; ++i) {
            auto val = preorder[i];
            auto pos = findPosition(inorder, start, end, val);
            auto node = new BinaryTreeNode(val);
            if (0 <= pos && pos < mid) {
                // at left
                prev->SetLeft(node);
            } else {
                // at right
                start = mid;
                while (!stack.empty() && pos > stack.top().second) {
                    prev = stack.top().first;
                    start = stack.top().second;
                    stack.pop();
                }
                prev->SetRight(node);
            }
            prev = node;
            stack.emplace(node, pos);
            mid = pos;
        }
    }
    return root.release();
}
