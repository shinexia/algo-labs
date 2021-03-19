#ifndef MYLIB_QSORT_H
#define MYLIB_QSORT_H

#pragma once

#include "mylib/util.h"

namespace mylib {

template <typename T>
inline void array_swap(T& nums, int a, int b) {
    auto t = nums[a];
    nums[a] = std::move(nums[b]);
    nums[b] = std::move(t);
}

// [start, end], T可以是(int*, std::vector), T的元素须且只需实现 operator<
// 如果用迭代器, nums[i] 改为 *(nums + i)
template <typename T>
int GenericPartition(T& nums, int start, int end) {
    int mid = int(uint32_t(start + end) >> 1);
    array_swap(nums, start, mid);
    auto const& pivot = nums[start];
    int i = start + 1, j = end;
    while (1) {
        for (; nums[i] < pivot && i < j; ++i) {
        }
        for (; nums[j] >= pivot && i <= j; --j) {
        }
        if (i >= j) {
            break;
        }
        array_swap(nums, i, j);
        ++i;
        --j;
    }
    if (j > start) {
        array_swap(nums, j, start);
    }
    return j;
}

template <typename T>
static void GenericQuickSort(T& nums, int start, int end) {
    if (start + 1 >= end) {
        if (start + 1 == end && nums[start] > nums[end]) {
            array_swap(nums, start, end);
        }
        return;
    }
    int mid = GenericPartition<T>(nums, start, end);
    GenericQuickSort(nums, start, mid - 1);
    GenericQuickSort(nums, mid + 1, end);
}

int Partition(int* nums, int start, int end);

int QuikSort(int nums[], int length);

}  // namespace mylib

#endif  // MYLIB_QSORT_H
