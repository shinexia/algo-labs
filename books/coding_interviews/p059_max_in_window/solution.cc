#include "solution.h"

std::vector<int> MaxInWindow(const std::vector<int>& nums, int winsize) {
    std::vector<int> result;
    if (nums.size() >= winsize) {
        std::deque<int> indexQueue;
        for (int i = 0; i < winsize; ++i) {
            while (!indexQueue.empty() && nums[i] >= nums[indexQueue.back()]) {
                indexQueue.pop_back();
            }
            indexQueue.push_back(i);
        }
        result.push_back(nums[indexQueue.front()]);
        for (int i = winsize; i < nums.size(); ++i) {
            if (indexQueue.front() + winsize <= i) {
                indexQueue.pop_front();
            }
            while (!indexQueue.empty() && nums[i] >= nums[indexQueue.back()]) {
                indexQueue.pop_back();
            }
            indexQueue.push_back(i);
            result.push_back(nums[indexQueue.front()]);
        }
    }
    return result;
}