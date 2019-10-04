#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

struct Case {
    int path[10];
    int n;
    int val;
};

bool nodeEqual(BinaryTreeNode* node, int val) {
    return node == nullptr ? val == -1 : node->Value == val;
}

TEST(p008, TestGetNext) {
    CVal nodes[] = {{1, 0}, {2, -1}, {4, -1}, {7, 0}, {9, 2},
                    {3, 2}, {5, -1}, {6, 1},  {8, -1}};

    int num_nodes = sizeof(nodes) / sizeof(CVal);
    auto head = mylib::MakeBinaryTree(nodes, num_nodes);
    PrintTreeF(std::cout, head.get()) << std::endl;

    Case cases[] = {
        {{0}, 0, 5},             // 右节点还有左节点
        {{-1, -1, 0}, 2, 7},     // 存在唯一右节点
        {{-1, -1, 1, 0}, 3, 2},  // 回溯
        {{-1, 1, 0}, 2, 1},      // 回溯
        {{1, 1, 0}, 2, -1},  // 回溯失败，最后一个节点没有下一个节点
    };
    int N = sizeof(cases) / sizeof(Case);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        auto node = GetFromPath(head.get(), c.path, c.n);
        auto next = GetNext(node);
        EXPECT_TRUE(nodeEqual(next, c.val))
            << "path: " << stringify(c.path, c.n)
            << ", node: " << PrintNode(node) << ", next: " << PrintNode(next)
            << ", expect val:" << c.val;
    }
    EXPECT_TRUE(nodeEqual(GetNext(nullptr), -1));
}
