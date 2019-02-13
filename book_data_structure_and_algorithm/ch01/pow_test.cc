#include "pow.h"

#include "myutil.h"
#include "gtest/gtest.h"

typedef struct Case_ {
  Pow_Type X;
  Pow_Type n;
  Pow_Type expect;
} Case;

typedef Pow_Type (*fn_pow)(Pow_Type X, Pow_Type n);

typedef struct FN_ {
  fn_pow fn;
  const char *name;
} FN;

TEST(TestPow, simple) {
  Case cases[] = {{0, 0, 1}, // special case
                  {0, 1, 0},  {0, 10, 0}, {1, 0, 1},     {1, 1, 1},
                  {1, 10, 1}, {2, 0, 1},  {2, 1, 2},     {2, 10, 1024},
                  {3, 0, 1},  {3, 1, 3},  {3, 10, 59049}};
  FN funcs[] = {{Pow, "Pow"}};

  int N = sizeof(cases) / sizeof(cases[0]);
  int K = sizeof(funcs) / sizeof(funcs[0]);

  for (int j = 0; j < K; j++) {
    FN *f = &(funcs[j]);
    for (int i = 0; i < N; i++) {
      Case *c = &(cases[i]);
      EXPECT_EQ(f->fn(c->X, c->n), c->expect)
          << "fn=" << f->name << ", X=" << c->X << ", n=" << c->n;
    }
  }
}
