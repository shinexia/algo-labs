#include "myutil.h"
#include "gtest/gtest.h"

extern "C" {
  extern unsigned int GCD(unsigned int M, unsigned int N);
}

typedef struct Case_ {
  unsigned int M;
  unsigned int N;
  unsigned int expect;
} Case;

typedef unsigned int(*fn_gcd)(unsigned int M, unsigned int N);

typedef struct FN_ {
  fn_gcd fn;
  const char* name;
} FN;

TEST(TestGcd, simple) {
  Case cases[] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {2, 3, 1},
    {2, 4, 2},
    {12, 8, 4},
    {8, 12, 4}
  };
  FN funcs[] = {
    {GCD, "GCD"}
  };
  for (int j=0; j<sizeof(funcs)/sizeof(funcs[0]); j++) {
    FN *f = &(funcs[j]);
    for (int i=0; i<sizeof(cases)/sizeof(cases[0]); i++) {
      Case* c = &(cases[i]);
      EXPECT_EQ(f->fn(c->M, c->N), c->expect) << "fn=" << f->name << ", M=" << c->M << ", N=" << c->N;
    }
  }
}
