#include "pow.h"

/* Tail Recursion */
static ElementType Pow_TR0(ElementType X, ElementType n, ElementType acc) {
  if (0 == n) {
    return acc;
  } else if ( 1 == n) {
    return X * acc;
  } else if ( (n & 0x1) == 0) {
    return Pow_TR0(X * X, n / 2, acc);
  } else {
    return Pow_TR0(X * X, n / 2, acc * X);
  }
}

ElementType Pow(ElementType X, ElementType n) {
  return Pow_TR0(X, n, 1);
}
