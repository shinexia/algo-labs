#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <sstream>

struct TreeNode;

typedef int ElementType;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree NewNode(ElementType X);

int Height(SearchTree T);
int Length(SearchTree T);

SearchTree MakeEmpty(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree NewTree(const ElementType *A, int N);

Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);

SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

std::string ToString(SearchTree T);

#endif  // BINARY_SEARCH_TREE_H
