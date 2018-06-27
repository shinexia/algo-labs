#include "myutil.h"
#include "gtest/gtest.h"

typedef int ElementType;
#define NotFound -1

extern "C" {
  int BinarySearch(const ElementType A[], ElementType x, int N);
}

typedef struct Case_ {
  int A[10];
  int N;
  ElementType x;
  int expect;
} Case;

TEST(TestBinarySearch, simple) {
  Case cases[] = {
    {{}, 0, 1, NotFound},
    {{1}, 1, 1, 0},
    {{1}, 1, -1, NotFound},
    {{1}, 1, 2, NotFound},
    {{1, 2}, 2, -1, NotFound},
    {{1, 2}, 2, 3, NotFound},
    {{1, 2}, 2, 1, 0},
    {{1, 2}, 2, 2, 1},
    {{-3, -2, -1, 0, 1, 2, 3, 4}, 8, -1, 2},
    {{-3, -2, -1, 0, 1, 2, 3, 4}, 8, 1, 4}
  };
  for (int i=0; i<sizeof(cases)/sizeof(cases[0]); i++) {
    const Case* c = &(cases[i]);
    EXPECT_EQ(c->expect, BinarySearch(c->A, c->x, c->N)) << my::stringify(c->A, c->N);
  }
}
