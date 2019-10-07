#pragma once

#include <functional>
#include <vector>

template <typename T>
void push_heap(std::vector<T>& vec, T num) {
    vec.push_back(num);
    std::push_heap(vec.begin(), vec.end(), std::less<T>());
};

template <typename T>
class DynamicArray {
   public:
    DynamicArray* Insert(T num) {
        size_t size = upper_.size() + lower_.size();
        if ((size & 1) == 0) {
            // add to upper
            if (!lower_.empty() && num < lower_[0]) {
                lower_.push_back(num);
                std::push_heap(lower_.begin(), lower_.end(), std::less<T>());
                num = lower_[0];
                std::pop_heap(lower_.begin(), lower_.end(), std::less<T>());
                lower_.pop_back();
            }
            upper_.push_back(num);
            std::push_heap(upper_.begin(), upper_.end(), std::greater<T>());
        } else {
            // add to lower
            if (num > upper_[0]) {
                upper_.push_back(num);
                std::push_heap(upper_.begin(), upper_.end(), std::greater<T>());
                num = upper_[0];
                std::pop_heap(upper_.begin(), upper_.end(), std::greater<T>());
                upper_.pop_back();
            }
            lower_.push_back(num);
            std::push_heap(lower_.begin(), lower_.end(), std::less<T>());
        }
        return this;
    }

    double getMedian() {
        size_t size = upper_.size() + lower_.size();
        if ((size & 1) == 1) {
            // odd
            return upper_[0];
        } else {
            // even
            T a = lower_[0];
            T b = upper_[0];
            int left = (a & 1) + (b & 1);
            return (a >> 1) + (b >> 1) + (left * 0.5);
        }
    }

   private:
    std::vector<T> upper_;
    std::vector<T> lower_;
};