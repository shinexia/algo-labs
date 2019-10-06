#include "solution.h"

int NumberOfOne1(int32_t n) {
    int count = 0;
    uint32_t flag = 1;
    while (flag) {
        if (n & flag) {
            ++count;
        }
        flag <<= 1;
    }
    return count;
}

int NumberOfOne(int32_t n) {
    int count = 0;
    while (n) {
        ++count;
        n &= n - 1;
    }
    return count;
}
