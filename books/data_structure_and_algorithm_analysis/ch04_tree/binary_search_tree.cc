#include "binary_search_tree.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    ElementType Element;
    SearchTree Left = nullptr;
    SearchTree Right = nullptr;
};

SearchTree NewNode(ElementType X) {
    SearchTree T = new TreeNode();
    if (T == nullptr) {
        fprintf(stderr, "FATAL: Out of Memory");
        exit(1);
    }
    T->Element = X;
    return T;
}

SearchTree NewTree(const ElementType *A, int N) {
    SearchTree T = nullptr;
    for (int i = 0; i < N; i++) {
        T = Insert(A[i], T);
    }
    return T;
}

SearchTree MakeEmpty(SearchTree T) {
    if (T != nullptr) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        delete T;
    }
    return nullptr;
}

int Height(SearchTree T) {
    if (T == nullptr) {
        return -1;
    }
    int l = Height(T->Left);
    int r = Height(T->Right);
    return 1 + (l > r ? l : r);
}

int Length(SearchTree T) {
    if (T == nullptr) {
        return 0;
    }
    int l = Length(T->Left);
    int r = Length(T->Right);
    return 1 + l + r;
}

SearchTree Insert(ElementType X, SearchTree T) {
    if (T == nullptr) {
        T = NewNode(X);
    } else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
    }
    // else eq ignored
    return T;
}

Position Find(ElementType X, SearchTree T) {
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

Position FindMin(SearchTree T) {
    if (T == nullptr) {
        return nullptr;
    } else if (T->Left != nullptr) {
        return FindMin(T->Left);
    } else {
        return T;
    }
}

Position FindMax(SearchTree T) {
    if (T == nullptr) {
        return nullptr;
    } else if (T->Right != nullptr) {
        return FindMax(T->Right);
    } else {
        return T;
    }
}

SearchTree Delete(ElementType X, SearchTree T) {
    if (T == nullptr) {
        return nullptr;
    } else if (X < T->Element) {
        T->Left = Delete(X, T->Left);
    } else if (X > T->Element) {
        T->Right = Delete(X, T->Right);
    } else if (T->Left && T->Right) {
        Position tmpCell = FindMin(T->Right);
        T->Element = Retrieve(tmpCell);
        T->Right = Delete(T->Element, T->Right);
    } else {
        SearchTree tmpCell = T;
        if (T->Left == nullptr) {
            T = T->Right;
        } else if (T->Right == nullptr) {
            T = T->Left;
        }
        delete tmpCell;
    }
    return T;
}

ElementType Retrieve(Position P) {
    if (P == nullptr) {
        fprintf(stderr, "FATAL: Null Pointer\n");
        exit(1);
    }
    return P->Element;
}

static void appendSpaces(std::ostringstream &oss, int N) {
    for (int i = 0; i < N; i++) {
        oss << ' ';
    }
}

static void printSearchTree(std::ostringstream &oss, SearchTree T, int depth) {
    appendSpaces(oss, depth * 2);
    if (T == nullptr) {
        oss << "nullptr\n";
    } else {
        oss << T->Element << "\n";
        printSearchTree(oss, T->Left, depth + 1);
        printSearchTree(oss, T->Right, depth + 1);
    }
}

std::string ToString(SearchTree T) {
    std::ostringstream oss;
    printSearchTree(oss, T, 0);
    return oss.str();
}
