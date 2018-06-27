#include "stdio.h"

#ifndef ElementType
#define ElementType int
#endif /* ElementType */

#define NotFound -1

int BinarySearch(const ElementType A[], ElementType x, int N) {
  int Low = 0, Mid, High = N - 1;
  while (Low <= High) {
    Mid = (Low + High) / 2;
    int y = A[Mid];
    if (y < x) {
      Low = Mid + 1;
    } else if (y > x) {
      High = Mid - 1;
    } else {
      /* Found */
      return Mid;
    }
  }
  return NotFound;
}
