#ifndef MYLIB_QSORT_H
#define MYLIB_QSORT_H

#pragma once

#include "mylib/util.h"

namespace mylib {

template <typename T>
inline void qsort_swap(T& nums, int a, int b) {
    auto t = nums[a];
    nums[a] = std::move(nums[b]);
    nums[b] = std::move(t);
}

// [start, end], T可以是(int*, std::vector), T的元素须且只需实现 operator<
// 如果用迭代器, nums[i] 改为 *(nums + i)
template <typename T>
int GenericPartition(T& nums, int start, int end) {
    if (start + 1 >= end) {
        if (start + 1 == end && !(nums[start] < nums[end])) {
            qsort_swap(nums, start, end);
        }
        return start;
    }
    int mid = int(uint(start + end) >> 1);
    qsort_swap(nums, start, mid);
    // pivot是引用，swap后会被修改
    auto& pivot = nums[start];
    int p1 = start + 1, p2 = end;
    while (p1 < p2) {
        // nums[p2] < pivot 或者 p2 = p1
        for (; p1 < p2 && !(nums[p2] < pivot); --p2) {
        }
        // nums[p1] >= pivot 或者 p1 = p2
        for (; p1 < p2 && nums[p1] < pivot; ++p1) {
        }
        if (p1 >= p2) {
            break;
        }
        qsort_swap(nums, p1, p2);
        ++p1;
        --p2;
    }
    if (!(nums[p2] < pivot)) {
        --p2;
        if (p2 == start) {
            // while没有发生过swap, 且为充要条件
            //   p2 只能是start+1(全部大于等于pivot)或者end(全部小于pivot)
            //   因: nums[p2] >= pivot, 因此p2只能等于start+1
            return start;
        }
        // else: while中发生过swap，则必定nums[p2-1] < pivot
    }
    qsort_swap(nums, p2, start);
    return p2;
}

int Partition(int* nums, int start, int end);

int QuikSort(int nums[], int length);

}  // namespace mylib

#endif  // MYLIB_QSORT_H