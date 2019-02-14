#include "binary_search_tree.h"

#include "mylib.h"
#include "gtest/gtest.h"
#include <stdio.h>

TEST(TestBinarySearchTree, simple) {
    ElementType A[] = {1, 2, 3, 4, 5};
    SearchTree T = MakeSearchTree(A, sizeof(A)/sizeof(ElementType));
    FPrintSearchTree(stdout, T);
    DeleteSearchTree(T);
}

