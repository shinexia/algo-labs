//
// Created by shine on 2/18/19.
//

#ifndef ALGORITHM_LABS_AVL_TREE_H
#define ALGORITHM_LABS_AVL_TREE_H

#include <string>

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

AvlTree NewNode(ElementType X);
AvlTree NewTree(const ElementType *A, int N);
int Height(AvlTree T);
int Length(AvlTree T);
std::string ToString(AvlTree T);
bool EqualTo(AvlTree T, const ElementType *A, int N);
bool IsAvlTree(AvlTree T);

#endif //ALGORITHM_LABS_AVL_TREE_H
