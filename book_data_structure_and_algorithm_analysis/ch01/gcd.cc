#include "gcd.h"

#ifdef __cplusplus
extern "C" {
#endif


ElementType GCD(ElementType M, ElementType N) {
    ElementType Rem;
    while (N > 0) {
        /* C语言中`%`是取余操作，不是取模 */
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}

#ifdef __cplusplus
}
#endif