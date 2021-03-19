#include "mylib/qsort.h"
#include "glog/logging.h"

namespace mylib {

int Partition(int nums[], int start, int end) {
    return GenericPartition<int*>(nums, start, end);
}

int QuikSort(int nums[], int length) {
    if (nums == nullptr || length <= 0) {
        return -1;
    }
    GenericQuickSort<int*>(nums, 0, length - 1);
    return 0;
}

}  // namespace mylib
