#include "solution.h"
#include <stack>

// 匿名namespace确保是内部类
namespace {
enum StateType { TRAVELING_START = 0, TRAVELING_LEFT, TRAVELING_RIGHT };

struct StackInfo {
    BinaryTreeNode* head = nullptr;
    StateType state = TRAVELING_START;
    int left = 0;
    int right = 0;

    StackInfo(BinaryTreeNode* head, StateType state, int left = 0,
              int right = 0)
        : head(head), state(state), left(left), right(right) {}

    void reset(BinaryTreeNode* head, StateType state, int left = 0,
               int right = 0) {
        this->head = head;
        this->state = state;
        this->left = left;
        this->right = right;
    }
};
}  // namespace

int TreeDepth(BinaryTreeNode* head) {
    if (head == nullptr) {
        return 0;
    }
    std::stack<StackInfo> stackList;
    StackInfo current(head, TRAVELING_START);
    while (true) {
        if (current.head == nullptr || current.state == TRAVELING_RIGHT) {
            int depth = current.head == nullptr
                            ? 0
                            : std::max(current.left, current.right) + 1;
            if (!stackList.empty()) {
                auto& top = stackList.top();
                if (top.state == TRAVELING_LEFT) {
                    top.left = depth;
                } else {
                    top.right = depth;
                }
                current = top;
                stackList.pop();
            } else {
                return depth;
            }
        } else if (current.state == TRAVELING_START) {
            current.state = TRAVELING_LEFT;
            stackList.push(current);
            current.reset(current.head->Left, TRAVELING_START);
        } else {
            current.state = TRAVELING_RIGHT;
            stackList.push(current);
            current.reset(current.head->Right, TRAVELING_RIGHT);
        }
    }
    return 0;
}
