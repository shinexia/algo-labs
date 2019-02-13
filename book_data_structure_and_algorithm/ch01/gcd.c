#include "gcd.h"

unsigned int GCD(unsigned int M, unsigned int N) {
    unsigned int Rem;
    while (N > 0) {
        /* C语言中`%`是取余操作，不是取模 */
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}
