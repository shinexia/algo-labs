#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree NewTreeNode(ElementType X) {
    SearchTree T = malloc(sizeof(struct TreeNode));
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

void DeleteSearchTree(SearchTree T) {
    if (T != NULL) {
        DeleteSearchTree(T->Left);
        DeleteSearchTree(T->Right);
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

static char *newSpaces(int N) {
    char *buf = (char *) malloc(N + 1);
    if (buf == NULL) {
        fprintf(stderr, "FATA: Out of Memory");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        buf[i] = ' ';
    }
    buf[N] = '\0';
    return buf;
}

static void printSearchTree(FILE *fd, SearchTree T, int depth) {
    char *prefix = newSpaces(depth * 2);
    if (T == NULL) {
        fprintf(fd, "%sNULL\n", prefix);
        free(prefix);
    } else {
        fprintf(fd, "%s%d\n", prefix, T->Element);
        free(prefix);
        printSearchTree(fd, T->Left, depth + 1);
        printSearchTree(fd, T->Right, depth + 1);
    }
}

void FPrintSearchTree(FILE *fd, SearchTree T) {
    fprintf(fd, "\n");
    printSearchTree(fd, T, 0);
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
    return NULL;
}

ElementType Retrieve(Position P) {
    return P->Element;
}


#ifdef __cplusplus
}
#endif
