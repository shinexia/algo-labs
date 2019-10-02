//
// Created by shine on 2/18/19.
//

#include "avl_tree.h"

#include "mylib.h"
#include "gtest/gtest.h"

typedef struct Case_ {
    ElementType A[20];
    ElementType Equal[20];
    int N;
    int Height;
    int Length;
    ElementType Max;
    ElementType Min;
    ElementType X;
    ElementType EqualX[20];
    ElementType NotFound;
    ElementType EqualEnd[20];
} Case;


TEST(TestBinarySearchTree, simple) {
    Case cases[] = {
            {
                    A: {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9},
                    Equal: {7, 4, 2, 1, 3, 6, 5, 13, 11, 9, 8, 10, 12, 15, 14, 16}, // 构建好的树
                    N: 16,
                    Height: 4,
                    Length: 16,
                    Max: 16,
                    Min: 1,
                    X: 12,
                    EqualX: {7, 4, 2, 1, 3, 6, 5, 13, 9, 8, 11, 10, 15, 14, 16}, // 删除X之后的树
                    NotFound: -1,
                    EqualEnd: {8, 4, 2, 3, 6, 5, 13, 10, 9, 11, 15, 14}, // 执行完所有删除以后
            },
    };

    int N = sizeof(cases) / sizeof(Case);

    for (int i = 0; i < N; i++) {
        const Case *c = &cases[i];
        AvlTree T = NewTree(c->A, c->N);
        EXPECT_TRUE(EqualTo(T, c->Equal, c->N));
        EXPECT_TRUE(IsAvlTree(T));
        EXPECT_EQ(Height(T), c->Height) << ToString(T);
        EXPECT_EQ(Length(T), c->Length) << ToString(T);
        EXPECT_EQ(Retrieve(FindMax(T)), c->Max) << ToString(T);
        EXPECT_EQ(Retrieve(FindMin(T)), c->Min) << ToString(T);
        EXPECT_EQ(Retrieve(Find(c->X, T)), c->X) << ToString(T);
        EXPECT_EQ(Find(c->NotFound, T), nullptr) << ToString(T);
        Delete(c->NotFound, T);
        EXPECT_EQ(Length(T), c->Length) << "Delete " << c->NotFound << "\n" << ToString(T);
        Delete(c->X, T);
        EXPECT_TRUE(EqualTo(T, c->EqualX, c->N - 1)) << "Delete " << c->X << "\n" << ToString(T);
        auto tmpDelete = Retrieve(T);
        Delete(tmpDelete, T);
        Delete(c->Max, T);
        Delete(c->Min, T);
        EXPECT_TRUE(EqualTo(T, c->EqualEnd, c->N - 4)) << "Delete " << c->Min << "\n" << ToString(T);
        MakeEmpty(T);
    }
}
