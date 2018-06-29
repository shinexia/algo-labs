

/* Tail Recursion */
static unsigned int Pow_TR0(unsigned int X, unsigned int n, unsigned int acc) {
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

unsigned int Pow(unsigned int X, unsigned int n) {
  return Pow_TR0(X, n, 1);
}
