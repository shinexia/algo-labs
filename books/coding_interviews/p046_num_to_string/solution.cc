#include "solution.h"

int GetTranslationCount(int number) {
    if (number < 0) {
        return 0;
    }
    int num = number, base = 1;
    while (num >= 10) {
        num /= 10;
        base *= 10;
    }
    int prev = num, counter = 1, prevCount1 = 1, prevCount2 = 1;
    while (base > 1) {
        number -= num * base;
        base /= 10;
        num = number / base;
        if ((prev == 1 || prev == 2) && num <= 5) {
            counter += prevCount2;
        }
        prev = num;
        prevCount2 = prevCount1;
        prevCount1 = counter;
    }
    return counter;
}
