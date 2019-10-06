#include "solution.h"
#include <cfenv>
#include <cmath>
#include <stdexcept>

#pragma STDC FENV_ACCESS ON

static double pow_(double base, int exponent) {
    if (exponent == 1) {
        return base;
    }
    double k = 1;
    do {
        if (exponent & 1 == 1) {
            k *= base;
            --exponent;
        } else {
            base *= base;
            exponent >>= 1;
        }
    } while (exponent > 1);
    return k * base;
}

double Power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent < 0) {
        double ret = 1.0 / pow_(base, -exponent);
        if (std::feclearexcept(FE_DIVBYZERO)) {
            return __builtin_inf();
        }
        return ret;
    }
    return pow_(base, exponent);
}
