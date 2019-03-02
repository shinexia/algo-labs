//
// Created by shine on 2/25/19.
//

#ifndef ALGORITHM_LABS_BINARY_HEAP_H
#define ALGORITHM_LABS_BINARY_HEAP_H

typedef int ElementType;

struct HeapStruct;

typedef struct HeapStruct* PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif //ALGORITHM_LABS_BINARY_HEAP_H
