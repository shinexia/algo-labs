#include "mylib/qsort.h"
#include "glog/logging.h"

namespace mylib {

template <typename T>
static void GenericQuickSortHelper(T& nums, int start, int end) {
    if (start + 1 >= end) {
        if (start + 1 == end && nums[start] > nums[end]) {
            qsort_swap(nums, start, end);
        }
        return;
    }
    int mid = GenericPartition<T>(nums, start, end);
    GenericQuickSortHelper(nums, start, mid - 1);
    GenericQuickSortHelper(nums, mid + 1, end);
}

int Partition(int nums[], int start, int end) {
    return GenericPartition<int*>(nums, start, end);
}

int QuikSort(int nums[], int length) {
    if (nums == nullptr || length < 0) {
        return -1;
    }

#if 1
    std::vector<int> vec(length);
    for (int i = 0; i < length; ++i) {
        vec[i] = nums[i];
    }
    GenericQuickSortHelper(vec, 0, length - 1);
    for (int i = 0; i < length; ++i) {
        nums[i] = vec[i];
    }
#else
    GenericQuickSortHelper<int*>(nums, 0, length - 1);
#endif

    return 0;
}

}  // namespace mylib
