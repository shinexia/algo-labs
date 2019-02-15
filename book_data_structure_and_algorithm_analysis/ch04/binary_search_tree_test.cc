#include "binary_search_tree.h"

#include "mylib.h"
#include "gtest/gtest.h"
#include <stdio.h>

typedef struct Case {
    ElementType A[10];
    int N;
    int Depth;
    int Count;
    ElementType Max;
    ElementType Min;
    ElementType X;
    ElementType NotFound;
} Case;


TEST(TestBinarySearchTree, simple) {
    Case cases[] = {
            {
                    A: {3, 3, 1, 2, 5, 4},
                    N: 6,
                    Depth: 3,
                    Count: 5,
                    Max: 5,
                    Min: 1,
                    X: 1,
                    NotFound: -1,
            },
    };

    int N = sizeof(cases) / sizeof(Case);

    for (int i = 0; i < N; i++) {
        const Case *c = &cases[i];
        SearchTree T = MakeSearchTree(c->A, c->N);
        EXPECT_EQ(GetSearchTreeDepth(T), c->Depth) << ToString(T);
        EXPECT_EQ(GetSearchTreeCount(T), c->Count) << ToString(T);
        EXPECT_EQ(Retrieve(FindMax(T)), c->Max) << ToString(T);
        EXPECT_EQ(Retrieve(FindMin(T)), c->Min) << ToString(T);
        EXPECT_EQ(Retrieve(Find(c->X, T)), c->X) << ToString(T);
        EXPECT_EQ(Find(c->NotFound, T), nullptr) << ToString(T);
        Delete(c->NotFound, T);
        EXPECT_EQ(GetSearchTreeCount(T), c->Count) << "Delete " << c->NotFound << "\n" << ToString(T);
        auto tmpDelete = Retrieve(T);
        Delete(tmpDelete, T);
        EXPECT_EQ(GetSearchTreeCount(T), c->Count - 1) << "Delete " << tmpDelete << "\n" << ToString(T);
        Delete(c->Max, T);
        EXPECT_EQ(GetSearchTreeCount(T), c->Count - 2) << "Delete " << c->Max << "\n" << ToString(T);
        Delete(c->Min, T);
        EXPECT_EQ(GetSearchTreeCount(T), c->Count - 3) << "Delete " << c->Min << "\n" << ToString(T);
        MakeEmpty(T);
    }
}
