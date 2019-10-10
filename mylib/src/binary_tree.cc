#include "mylib/binary_tree.h"
#include "glog/logging.h"

#include <stack>

namespace mylib {

BinaryTreeNode::~BinaryTreeNode() {
    // LOG(INFO) << "btree: " << Value << " deleted";
}

BinaryTreeNode* BinaryTreeNode::RemoveChild(BinaryTreeNode* child) {
    if (child == nullptr) {
        return this;
    }
    if (Left == child) {
        Left->Parent = nullptr;
        Left = nullptr;
    }
    if (Right == child) {
        Right->Parent = nullptr;
        Right = nullptr;
    }
    return this;
}

BinaryTreeNode* BinaryTreeNode::SetParent(BinaryTreeNode* right) {
    if (Parent != nullptr) {
        Parent->RemoveChild(this);
    }
    Parent = right;
    return this;
}

BinaryTreeNode* BinaryTreeNode::SetLeft(BinaryTreeNode* left) {
    if (Left == left) {
        return this;
    }
    if (left != nullptr) {
        left->SetParent(this);
    }
    auto t = Left;
    Left = left;
    DeleteBinaryTree(t);
    return this;
}

BinaryTreeNode* BinaryTreeNode::SetRight(BinaryTreeNode* right) {
    if (Right == right) {
        return this;
    }
    if (right != nullptr) {
        right->SetParent(this);
    }
    auto t = Right;
    Right = right;
    DeleteBinaryTree(t);
    return this;
}

deleted_unique_ptr<BinaryTreeNode> MakeUnique(BinaryTreeNode* head) {
    return deleted_unique_ptr<BinaryTreeNode>(head, DeleteBinaryTree);
}

void DeleteBinaryTree(BinaryTreeNode* head) {
    if (head == nullptr) {
        return;
    }
    std::stack<BinaryTreeNode*> right_stack;
    do {
        auto t = head;
        if (head->Left) {
            if (head->Right) {
                right_stack.push(head->Right);
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
    } while (head != nullptr);
    return;
}

std::vector<std::string> Serialize(const BinaryTreeNode* root) {
    std::vector<std::string> vec;
    if (root == nullptr) {
        return vec;
    }
    vec.push_back(std::to_string(root->Value));
    std::deque<const BinaryTreeNode*> queue;
    queue.push_back(root);
    int nullCount = 0;
    do {
        const BinaryTreeNode* next = queue.front();
        if (next->Left) {
            if (nullCount > 0) {
                while (nullCount--) {
                    vec.push_back(NULL_INT_NAME);
                }
                // now nullCount = -1
                nullCount = 0;
            }
            vec.push_back(std::to_string(next->Left->Value));
            queue.push_back(next->Left);
        } else {
            ++nullCount;
        }
        if (next->Right) {
            if (nullCount > 0) {
                while (nullCount--) {
                    vec.push_back(NULL_INT_NAME);
                }
                // now nullCount = -1
                nullCount = 0;
            }
            vec.push_back(std::to_string(next->Right->Value));
            queue.push_back(next->Right);
        } else {
            ++nullCount;
        }
        queue.pop_front();
    } while (!queue.empty());
    return vec;
}

template <typename T>
static deleted_unique_ptr<BinaryTreeNode> GenericDeserialize(const T& vals,
                                                             int num_val) {
    BinaryTreeNode* head = nullptr;
    if (num_val > 0) {
        head = new BinaryTreeNode(vals[0]);
        std::deque<BinaryTreeNode*> queue;
        queue.push_back(head);
        int i = 1;
        while (i < num_val) {
            if (vals[i] != NULL_INT) {
                if (queue.empty()) {
                    throw std::runtime_error(
                        mylib::string_format("empty queue, i=%d", i));
                }
                BinaryTreeNode* left = new BinaryTreeNode(vals[i]);
                queue.front()->SetLeft(left);
                queue.push_back(left);
            }
            ++i;
            if (i < num_val && vals[i] != NULL_INT) {
                if (queue.empty()) {
                    throw std::runtime_error(
                        mylib::string_format("empty queue, i=%d", i));
                }
                BinaryTreeNode* right = new BinaryTreeNode(vals[i]);
                queue.front()->SetRight(right);
                queue.push_back(right);
            }
            ++i;
            if (!queue.empty()) {
                queue.pop_front();
            }
        };
    }
    return deleted_unique_ptr<BinaryTreeNode>(head, DeleteBinaryTree);
}

deleted_unique_ptr<BinaryTreeNode> Deserialize(const int* vals, int num_val) {
    return GenericDeserialize<const int*>(vals, num_val);
}

deleted_unique_ptr<BinaryTreeNode> Deserialize(const std::vector<int>& vals) {
    return GenericDeserialize<std::vector<int>>(vals, vals.size());
}

deleted_unique_ptr<BinaryTreeNode> MakeBinaryTree(const CVal* vals,
                                                  int num_vals) {
    deleted_unique_ptr<BinaryTreeNode> head(nullptr, DeleteBinaryTree);
    BinaryTreeNode* prev;
    std::stack<BinaryTreeNode*> stack;
    for (int i = 0; i < num_vals; ++i) {
        auto& node = vals[i];
        auto t = new BinaryTreeNode(node.Val);
        if (i == 0) {
            head.reset(t);
        } else {
            if (node.Move < 0) {
                prev->SetLeft(t);
            } else if (node.Move == 0) {
                prev->SetRight(t);
            } else {
                for (int j = 0; j < node.Move; ++j) {
                    if (stack.empty()) {
                        LOG(FATAL) << "pop overflow val: " << node.Val
                                   << ", move: " << node.Move
                                   << ", over: " << node.Move - j + 1;
                    }
                    stack.pop();
                }
                if (stack.empty()) {
                    LOG(FATAL) << "pop overflow val: " << node.Val
                               << ", move: " << node.Move << ", over: " << 1;
                }
                stack.top()->SetRight(t);
            }
        }
        prev = t;
        stack.push(t);
    }
    return head;
}

BinaryTreeNode* BST_Insert(BinaryTreeNode* root, BinaryTreeNode* node) {
    if (root == nullptr) {
        return node;
    }
    if (node == nullptr) {
        return root;
    }
    if (node->Value < root->Value) {
        root->Left = BST_Insert(root->Left, node);
    } else {
        root->Right = BST_Insert(root->Right, node);
    }
    return root;
}

deleted_unique_ptr<BinaryTreeNode> MakeBinarySearchTree(const int vals[],
                                                        int num_val) {
    BinaryTreeNode* head = nullptr;
    for (int i = 0; i < num_val; ++i) {
        head = BST_Insert(head, new BinaryTreeNode(vals[i]));
    }
    return deleted_unique_ptr<BinaryTreeNode>(head, DeleteBinaryTree);
}

static int _PrintTreeF(std::ostream& os, const BinaryTreeNode* head,
                       int depth) {
    if (head->Right) {
        _PrintTreeF(os, head->Right, depth + 1);
        os << "\n";
    }
    for (int i = 0; i < depth; ++i) {
        os << "  ";
    }
    os << head->Value;
    if (head->Left) {
        os << "\n";
        _PrintTreeF(os, head->Left, depth + 1);
    }
    return 0;
}

std::ostream& PrintTreeF(std::ostream& os, const BinaryTreeNode* head) {
    if (head != nullptr) {
        _PrintTreeF(os, head, 0);
    } else {
        os << "<nil>";
    }
    return os;
}

std::ostream& PrintNodeF(std::ostream& os, const BinaryTreeNode* node) {
    if (node == nullptr) {
        os << "<nil>";
    } else {
        os << node->Value;
    }
    return os;
}

std::string PrintTree(const BinaryTreeNode* head) {
    std::ostringstream oss;
    PrintTreeF(oss, head);
    return oss.str();
}

std::string PrintNode(const BinaryTreeNode* node) {
    std::ostringstream oss;
    PrintNodeF(oss, node);
    return oss.str();
}

// 前序遍历，先访问根节点，再访问左子节点，最后访问右子节点
bool CheckPreOrder(const BinaryTreeNode* head, const int* preorders,
                   int num_orders) {
    if (head == nullptr) {
        return num_orders == 0;
    }
    std::stack<const BinaryTreeNode*> stack;
    int i = 0;
    while (true) {
        if (i >= num_orders) {
            return head == nullptr;
        }
        int val = preorders[i++];
        if (val != head->Value) {
            LOG(ERROR) << "check failed, i:" << i - 1 << ", val:" << val
                       << ", node:" << head->Value;
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
            return i == num_orders;
        }
    }
    return true;
}

// 中序遍历，先访问左子节点，再访问根节点，最后访问右子节点
bool CheckInOrder(const BinaryTreeNode* head, const int* inorders,
                  int num_orders) {
    if (head == nullptr) {
        return num_orders == 0;
    }
    std::stack<const BinaryTreeNode*> stack;
    bool is_back = false;
    int i = 0;
    while (true) {
        if (i >= num_orders) {
            return head == nullptr;
        }
        if (head->Left && !is_back) {
            stack.push(head);
            head = head->Left;
        } else {
            is_back = false;
            auto val = inorders[i++];
            if (val != head->Value) {
                LOG(ERROR) << "check failed, i:" << i - 1 << ", val:" << val
                           << ", node:" << head->Value;
                return false;
            }
            if (head->Right) {
                head = head->Right;
            } else if (!stack.empty()) {
                head = stack.top();
                is_back = true;
                stack.pop();
            } else {
                return i == num_orders;
            }
        }
    }
    return true;
}

// 后序遍历，先访问左子节点，再访问右子节点，最后访问根节点
bool CheckPostOrder(const BinaryTreeNode* head, const int* postorders,
                    int num_orders) {
    if (head == nullptr) {
        return num_orders == 0;
    }
    std::stack<std::pair<const BinaryTreeNode*, int>> stack;
    int back_flag = 0;
    int i = 0;
    while (true) {
        if (i >= num_orders) {
            return head == nullptr;
        }
        if (head->Left && back_flag < 1) {
            stack.emplace(head, 1);
            head = head->Left;
            back_flag = 0;
        } else if (head->Right && back_flag < 2) {
            stack.emplace(head, 2);
            head = head->Right;
            back_flag = 0;
        } else {
            auto val = postorders[i++];
            if (val != head->Value) {
                LOG(ERROR) << "check failed, i:" << i - 1 << ", val:" << val
                           << ", node:" << head->Value;
                return false;
            }
            back_flag = 0;
            if (!stack.empty()) {
                auto& top = stack.top();
                head = top.first;
                back_flag = top.second;
                stack.pop();
            } else {
                return i == num_orders;
            }
        }
    }
    return true;
}

BinaryTreeNode* GetFromPath(BinaryTreeNode* head, const int* path,
                            int num_path) {
    for (int i = 0; i < num_path && head != nullptr; ++i) {
        int next = path[i];
        if (next == 0) {
            return head;
        } else if (next < 0) {
            head = head->Left;
        } else {
            head = head->Right;
        }
    }
    return head;
}

}  // namespace mylib
