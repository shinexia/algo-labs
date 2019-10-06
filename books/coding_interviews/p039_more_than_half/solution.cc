#include "solution.h"
#include <stdexcept>
#include "mylib/qsort.h"

static int checkValid(int* number, int length, int result) {
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (number[i] == result) {
            ++counter;
        }
    }
    counter <<= 1;
    if (counter <= length) {
        throw std::runtime_error("not found");
    }
    return result;
}

int ImplWithPartition(int* number, int length) {
    if (number == nullptr || length <= 0) {
        throw std::invalid_argument("null number or negative length");
    }
    if (length <= 2) {
        if (length == 2 && number[0] != number[1]) {
            throw std::runtime_error("not found");
        }
        return number[0];
    }
    int mid = length >> 1, start = 0, end = length - 1, index;
    do {
        index = mylib::Partition(number, start, end);
        if (index == mid) {
            break;
        } else if (index < mid) {
            start = index + 1;
        } else {
            end = index - 1;
        }
    } while (true);
    int target = number[mid];
    return checkValid(number, length, target);
}

int MoreThanHalfNum(int* number, int length) {
    if (number == nullptr || length <= 0) {
        throw std::invalid_argument("null number or negative length");
    }
    if (length <= 2) {
        if (length == 2 && number[0] != number[1]) {
            throw std::runtime_error("not found");
        }
        return number[0];
    }
    int result = number[0];
    int counter = 1;
    for (int i = 1; i < length; ++i) {
        if (counter == 0) {
            result = number[i];
            counter = 1;
        } else if (number[i] == result) {
            ++counter;
        } else {
            --counter;
        }
    }
    return checkValid(number, length, result);
}
