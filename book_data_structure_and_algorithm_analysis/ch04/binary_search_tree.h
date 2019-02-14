#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct TreeNode;

typedef int ElementType;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree NewTreeNode(ElementType X);

int GetSearchTreeDepth(SearchTree T);
int GetSearchTreeCount(SearchTree T);

void FPrintSearchTree(FILE* fd, SearchTree T);

void DeleteSearchTree(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree MakeSearchTree(const ElementType A[], int N);

Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);

SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#ifdef __cplusplus
}
#endif

#endif  // BINARY_SEARCH_TREE_H
