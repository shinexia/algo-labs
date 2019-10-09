#include "solution.h"
#include <cmath>
#include "glog/logging.h"

int NumberOfOne(int n) {
    int counter = 0;
    while (n) {
        if (n % 10 == 1) {
            ++counter;
        }
        n /= 10;
    }
    return counter;
}

int simple(int n) {
    int counter = 0;
    for (int i = 1; i <= n; ++i) {
        counter += NumberOfOne(i);
    }
    return counter;
}

static inline int lessThan1(int base, int exp) { return exp * base / 10; }

int lessThan(int num, int base, int exp) {
    int a = lessThan1(base, exp);
    return num < 1 ? 0 : num == 1 ? a : a * num + base;
}

int NumberOfOneBetween(int n) {
    int num = n, base = 1, exp = 0;
    while (num >= 10) {
        ++exp;
        num /= 10;
        base *= 10;
    }
    int counter = 0;
    while (num > 0 || exp > 0) {
        int left = n - num * base;
        if (num > 0) {
            int a = lessThan1(base, exp);
            counter += num == 1 ? (a + left + 1) : (a * num + base);
        }
        base /= 10;
        --exp;
        n = left;
        num = base == 0 ? 0 : left / base;
    }
    return counter;
}
