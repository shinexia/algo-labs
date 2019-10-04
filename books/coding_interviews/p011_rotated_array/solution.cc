#include "solution.h"
#include <stdexcept>
#include "glog/logging.h"
#include "mylib/mylib.h"

int direct(int* number, int p1, int p2) {
    int ret = number[p1];
    for (int i = p1 + 1; i <= p2; ++i) {
        if (number[i] < ret) {
            ret = number[i];
        }
    }
    return ret;
}

int Min(int* number, int num) {
    if (number == nullptr || num <= 0) {
        throw std::invalid_argument("null number or zero num");
    }
    if (num == 1) {
        return number[0];
    }
    int p1 = 0, p2 = num - 1;
    while (number[p1] >= number[p2]) {
        if (p1 + 1 == p2) {
            p1 = p2;
            break;
        }
        int mid = (p1 + p2) / 2;
        if (number[p1] == number[mid] && number[mid] == number[p2]) {
            return direct(number, p1, p2);
        } else if (number[p1] <= number[mid]) {
            p1 = mid;
        } else {
            p2 = mid;
        }
    }
    return number[p1];
}
