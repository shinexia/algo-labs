#include "binary_search.h"


#ifdef __cplusplus
extern "C" {
#endif


int BinarySearch(const ElementType A[], ElementType x, int N) {
    int Low = 0, Mid, High = N - 1;
    if (N > 0 && (x < A[Low] || x > A[High])) {
        return NotFound;
    }
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

#ifdef __cplusplus
}
#endif
