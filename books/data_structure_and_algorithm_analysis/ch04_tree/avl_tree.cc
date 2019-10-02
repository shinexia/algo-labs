//
// Created by shine on 2/18/19.
//

#include "avl_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <iostream>

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static void UpdateHeight(Position P) {
    P->Height = std::max(Height(P->Left), Height(P->Right)) + 1;
}

AvlTree NewNode(ElementType X) {
    auto T = (AvlTree) malloc(sizeof(struct AvlNode));
    T->Element = X;
    T->Left = T->Right = nullptr;
    UpdateHeight(T);
    return T;
}

AvlTree NewTree(const ElementType *A, int N) {
    AvlTree T = nullptr;
    for (int i = 0; i < N; i++) {
        T = Insert(A[i], T);
//        std::cout << "Insert: " << A[i] << std::endl;
//        std::cout << ToString(T) << "\n" << std::endl;
    }
    return T;
}

int Height(AvlTree T) {
    if (T == nullptr) {
        return -1;
    }
    return T->Height;
}

int Length(AvlTree T) {
    if (T == nullptr) {
        return 0;
    }
    return Length(T->Left) + Length(T->Right) + 1;
}

static bool isEqualTo_(AvlTree T, const ElementType A[], int N, int &i) {
    if (i >= N) {
        return false;
    }
    if (T->Element != A[i]) {
        return false;
    }
    i++;
    if (T->Left != nullptr && !isEqualTo_(T->Left, A, N, i)) {
        return false;
    } else if (T->Right != nullptr && !isEqualTo_(T->Right, A, N, i)) {
        return false;
    }
    return true;
}

bool EqualTo(AvlTree T, const ElementType *A, int N) {
    if (T == nullptr) {
        return N == 0;
    }
    int i = 0;
    return isEqualTo_(T, A, N, i);
}

AvlTree MakeEmpty(AvlTree T) {
    if (T == nullptr) {
        return nullptr;
    }
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
    return nullptr;
}

Position Find(ElementType X, AvlTree T) {
    if (T == nullptr) {
        return nullptr;
    } else if (X < T->Element) {
        return Find(X, T->Left);
    } else if (X > T->Element) {
        return Find(X, T->Right);
    } else {
        return T;
    }
}

Position FindMin(AvlTree T) {
    if (T == nullptr) {
        return nullptr;
    } else if (T->Left != nullptr) {
        return FindMin(T->Left);
    } else {
        return T;
    }
}

Position FindMax(AvlTree T) {
    if (T == nullptr) {
        return nullptr;
    } else if (T->Right != nullptr) {
        return FindMax(T->Right);
    } else {
        return T;
    }
}

static Position SingleRotateLeft(Position K2) {
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    UpdateHeight(K2);
    UpdateHeight(K1);
    return K1;
}

static Position SingleRotateRight(Position K2) {
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    UpdateHeight(K2);
    UpdateHeight(K1);
    return K1;
}

static Position DoubleRotateLeft(Position K3) {
    Position K1, K2;
    K1 = K3->Left;
    K2 = K1->Right;
    K3->Left = K2->Right;
    K1->Right = K2->Left;
    K2->Left = K1;
    K2->Right = K3;
    UpdateHeight(K3);
    UpdateHeight(K1);
    UpdateHeight(K2);
    return K2;
}

static Position DoubleRotateRight(Position K3) {
    Position K1, K2;
    K1 = K3->Right;
    K2 = K1->Left;
    K3->Right = K2->Left;
    K1->Left = K2->Right;
    K2->Left = K3;
    K2->Right = K1;
    UpdateHeight(K3);
    UpdateHeight(K1);
    UpdateHeight(K2);
    return K2;
}

AvlTree Insert(ElementType X, AvlTree T) {
    if (T == nullptr) {
        T = NewNode(X);
    } else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) >= 2) {
            if (X < T->Left->Element) {
                T = SingleRotateLeft(T);
            } else {
                T = DoubleRotateLeft(T);
            }
        }
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) >= 2) {
            if (X > T->Right->Element) {
                T = SingleRotateRight(T);
            } else {
                T = DoubleRotateRight(T);
            }
        }
    }
    // else ignored
    UpdateHeight(T);
    return T;
}

AvlTree Delete(ElementType X, AvlTree T) {
    Position tmpT;
    if (T == nullptr) {
        return T;
    } else if (X < T->Element) {
        T->Left = Delete(X, T->Left);
        if (Height(T->Right) - Height(T->Left) >= 2) {
            if (Height(T->Right->Right) - Height(T->Right->Left) >= 0) {
                T = SingleRotateRight(T);
            } else {
                T = DoubleRotateRight(T);
            }
        }
    } else if (X > T->Element) {
        T->Right = Delete(X, T->Right);
        if (Height(T->Left) - Height(T->Right) >= 2) {
            if (Height(T->Left->Left) - Height(T->Left->Right) >= 0) {
                T = SingleRotateLeft(T);
            } else {
                T = DoubleRotateRight(T);
            }
        }
    } else {
        if (T->Left && T->Right) {
            tmpT = FindMin(T->Right);
            T->Element = tmpT->Element;
            T->Right = Delete(tmpT->Element, T->Right);
        } else {
            tmpT = T;
            if (T->Left) {
                T = T->Left;
            } else {
                T = T->Right;
            }
            free(tmpT);
        }
    }
    return T;
}

ElementType Retrieve(Position P) {
    if (P == nullptr) {
        fprintf(stderr, "FATAL: NULL Pointer");
        exit(1);
    }
    return P->Element;
}

static void appendSpaces(std::ostringstream &oss, int N) {
    for (int i = 0; i < N; i++) {
        oss << ' ';
    }
}

static void printTree(std::ostringstream &oss, AvlTree T, int depth) {
    appendSpaces(oss, depth * 2);
    if (T == nullptr) {
        oss << "NULL\n";
    } else {
        oss << Retrieve(T) << "\n";
        printTree(oss, T->Left, depth + 1);
        printTree(oss, T->Right, depth + 1);
    }
}

std::string ToString(AvlTree T) {
    std::ostringstream oss;
    printTree(oss, T, 0);
    return oss.str();
}

int CalcHeight(AvlTree T) {
    if (T == nullptr) {
        return -1;
    }
    return std::max(CalcHeight(T->Left), CalcHeight(T->Right)) + 1;
}

bool IsAvlTree(AvlTree T) {
    if (T == nullptr) {
        return true;
    }
    return IsAvlTree(T->Left) && IsAvlTree(T->Right) && std::abs(CalcHeight(T->Left) - CalcHeight(T->Right)) <= 1;
}
