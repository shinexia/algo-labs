#include "pow.h"

#include "util.h"
#include "gtest/gtest.h"


typedef struct Case_ {
  int X;
  int n;
  int expect;
} Case;

typedef unsigned int (*fn_pow)(unsigned int X, unsigned n);

typedef struct FN_ {
  fn_pow fn;
  const char* name;
} FN;

TEST(TestPow, simple) {
  Case cases[] = {
    {0, 0, 1}, // special case
    {0, 1, 0},
    {0, 10, 0},
    {1, 0, 1},
    {1, 1, 1},
    {1, 10, 1},
    {2, 0, 1},
    {2, 1, 2},
    {2, 10, 1024},
    {3, 0, 1},
    {3, 1, 3},
    {3, 10, 59049}
  };
  FN funcs[] = {
    {Pow, "Pow"}
  };
  for (int j=0; j<sizeof(funcs)/sizeof(funcs[0]); j++) {
    FN* f= &(funcs[j]);
    for (int i=0; i<sizeof(cases)/sizeof(cases[0]); i++) {
      Case* c = &(cases[i]);
      EXPECT_EQ(f->fn(c->X, c->n), c->expect) << "fn=" << f->name << ", X=" << c->X << ", n=" << c->n;
    }
  }
}
