#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int ElementType;

#define NotFound -1

int BinarySearch(const ElementType A[], ElementType x, int N);

#ifdef __cplusplus
}
#endif

#endif  // BINARY_SEARCH_H
