#include "pow.h"

/* Tail Recursion */
static Pow_Type Pow_TR0(Pow_Type X, Pow_Type n, Pow_Type acc) {
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

Pow_Type Pow(Pow_Type X, Pow_Type n) {
  return Pow_TR0(X, n, 1);
}
