#include "mylib/binary_tree.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

using namespace mylib;

namespace {
bool arrayEqual(const std::vector<std::string>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (b[i] == NULL_INT) {
            if (a[i] != NULL_INT_NAME) {
                return false;
            }
        } else if (a[i] != std::to_string(b[i])) {
            return false;
        }
    }
    return true;
}
}  // namespace

TEST(mylib, DeserializeTest) {
    int vals[] = {1,        2, 3,        4,        9,        5,        6,
                  NULL_INT, 7, NULL_INT, NULL_INT, NULL_INT, NULL_INT, 8};
    int num_vals = sizeof(vals) / sizeof(int);
    std::vector<int> vec(num_vals);
    for (int i = 0; i < num_vals; ++i) {
        vec[i] = vals[i];
    }
    auto head = mylib::Deserialize(vec);
    LOG(INFO) << "\n" << mylib::PrintTree(head.get());
    auto serial = mylib::Serialize(head.get());
    EXPECT_TRUE(arrayEqual(serial, vec)) << "serial: " << serial;
}

TEST(mylib, MakeBinaryTreeTest) {
    struct Case {
        int preorder[20];
        int inorder[20];
        int length;
    };

    CVal nodes[] = {{1, 0}, {2, -1}, {4, -1}, {7, 0}, {9, 2},
                    {3, 2}, {5, -1}, {6, 1},  {8, -1}};
    int preorders[] = {1, 2, 4, 7, 9, 3, 5, 6, 8};
    int inorders[] = {4, 7, 2, 9, 1, 5, 3, 8, 6};
    int post_orders[] = {7, 4, 9, 2, 5, 8, 6, 3, 1};

    int N = sizeof(nodes) / sizeof(mylib::CVal);
    auto head = mylib::MakeBinaryTree(nodes, N);
    LOG(INFO) << "\n" << mylib::PrintTree(head.get());
    LOG(INFO) << mylib::Serialize(head.get());

    EXPECT_TRUE(CheckPreOrder(head.get(), preorders, N));
    EXPECT_TRUE(CheckInOrder(head.get(), inorders, N));
    EXPECT_TRUE(CheckPostOrder(head.get(), post_orders, N));
}

TEST(mylib, MakeBinarySearchTreeTest) {
    struct Case {
        int vals[20];
        int num_val;
    };
    Case cases[] = {
        {{1, 2, 4, 7, 9, 3, 5, 6, 8}, 9},
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto head = MakeBinarySearchTree(c.vals, c.num_val);
        LOG(INFO) << "\n" << PrintTree(head.get());
        LOG(INFO) << mylib::Serialize(head.get());
    }
}