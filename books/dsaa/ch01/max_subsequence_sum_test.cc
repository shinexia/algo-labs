#include "myutil.h"
#include "gtest/gtest.h"
#include <sstream>

extern "C" {
  extern int MaxSubsequenceSum(const int A[], int N);
}

typedef struct Case {
  int a[10];
  int n;
  int expect;
} Case;

TEST(TestMaxSubsequenceSum, simple) {
  Case cases[] = {
    {{}, 0, 0},
    {{1}, 1, 1},
    {{-1}, 1, 0},
    {{1, 2}, 2, 3},
    {{-1, 2}, 2, 2},
    {{1, -2}, 2, 1},
    {{-1, -2}, 2, 0},
    {{1, 2, 3}, 3, 6},
    {{-1, 2, 3}, 3, 5},
    {{1, -2, 3}, 3, 3},
    {{1, 2, -3}, 3, 3},
    {{1, -2, -3}, 3, 1},
    {{-1, -2, 3}, 3, 3},
    {{-1, 3, -1, -1, 2, 3, 4}, 7, 10}
  };
  for (int i=0; i<sizeof(cases) / sizeof(cases[0]); i++) {
    const Case* c = &(cases[i]);
    EXPECT_EQ(MaxSubsequenceSum(c->a, c->n), c->expect) << "a=" << my::stringify(c->a, c->n);
    ;
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
