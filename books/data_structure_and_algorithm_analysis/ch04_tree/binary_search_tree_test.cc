#include "binary_search_tree.h"

#include "mylib/util.h"
#include "gtest/gtest.h"
#include <stdio.h>

struct Case {
    ElementType A[10];
    int N;
    int Height;
    int Length;
    ElementType Max;
    ElementType Min;
    ElementType X;
    ElementType NotFound;
};


TEST(TestBinarySearchTree, simple) {
    Case cases[] = {
            {
                    A: {3, 3, 1, 2, 5, 4},
                    N: 6,
                    Height: 2,
                    Length: 5,
                    Max: 5,
                    Min: 1,
                    X: 1,
                    NotFound: -1,
            },
    };

    int N = sizeof(cases) / sizeof(Case);

    for (int i = 0; i < N; i++) {
        const Case *c = &cases[i];
        SearchTree T = NewTree(c->A, c->N);
        EXPECT_EQ(Height(T), c->Height) << ToString(T);
        EXPECT_EQ(Length(T), c->Length) << ToString(T);
        EXPECT_EQ(Retrieve(FindMax(T)), c->Max) << ToString(T);
        EXPECT_EQ(Retrieve(FindMin(T)), c->Min) << ToString(T);
        EXPECT_EQ(Retrieve(Find(c->X, T)), c->X) << ToString(T);
        EXPECT_EQ(Find(c->NotFound, T), nullptr) << ToString(T);
        Delete(c->NotFound, T);
        EXPECT_EQ(Length(T), c->Length) << "Delete " << c->NotFound << "\n" << ToString(T);
        auto tmpDelete = Retrieve(T);
        Delete(tmpDelete, T);
        EXPECT_EQ(Length(T), c->Length - 1) << "Delete " << tmpDelete << "\n" << ToString(T);
        Delete(c->Max, T);
        EXPECT_EQ(Length(T), c->Length - 2) << "Delete " << c->Max << "\n" << ToString(T);
        Delete(c->Min, T);
        EXPECT_EQ(Length(T), c->Length - 3) << "Delete " << c->Min << "\n" << ToString(T);
        MakeEmpty(T);
    }
}
