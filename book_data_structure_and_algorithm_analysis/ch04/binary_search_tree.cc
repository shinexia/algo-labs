#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree NewTreeNode(ElementType X) {
    SearchTree T = (SearchTree) malloc(sizeof(struct TreeNode));
    if (T == NULL) {
        fprintf(stderr, "FATAL: Out of Memory");
        exit(1);
    }
    T->Element = X;
    T->Left = T->Right = NULL;
    return T;
}

SearchTree MakeSearchTree(const ElementType A[], int N) {
    SearchTree T = NULL;
    for (int i = 0; i < N; i++) {
        T = Insert(A[i], T);
    }
    return T;
}

SearchTree MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
}

int GetSearchTreeDepth(SearchTree T) {
    if (T == NULL) {
        return 0;
    }
    int l = GetSearchTreeDepth(T->Left);
    int r = GetSearchTreeDepth(T->Right);
    return 1 + (l > r ? l : r);
}

int GetSearchTreeCount(SearchTree T) {
    if (T == NULL) {
        return 0;
    }
    int l = GetSearchTreeCount(T->Left);
    int r = GetSearchTreeCount(T->Right);
    return 1 + l + r;
}

SearchTree Insert(ElementType X, SearchTree T) {
    if (T == NULL) {
        T = NewTreeNode(X);
    } else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
    }
    // else eq ignored
    return T;
}

Position Find(ElementType X, SearchTree T) {
    if (T == NULL) {
        return NULL;
    } else if (X < T->Element) {
        return Find(X, T->Left);
    } else if (X > T->Element) {
        return Find(X, T->Right);
    } else {
        return T;
    }
}

Position FindMin(SearchTree T) {
    if (T == NULL) {
        return NULL;
    } else if (T->Left != NULL) {
        return FindMin(T->Left);
    } else {
        return T;
    }
}

Position FindMax(SearchTree T) {
    if (T == NULL) {
        return NULL;
    } else if (T->Right != NULL) {
        return FindMax(T->Right);
    } else {
        return T;
    }
}

SearchTree Delete(ElementType X, SearchTree T) {
    if (T == NULL) {
        return NULL;
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
        if (T->Left == NULL) {
            T = T->Right;
        } else if (T->Right == NULL) {
            T = T->Left;
        }
        free(tmpCell);
    }
    return T;
}

ElementType Retrieve(Position P) {
    if (P == NULL) {
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
        oss << "NULL\n";
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
