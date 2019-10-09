#pragma once

#include <deque>
#include <stdexcept>
#include <vector>

std::vector<int> MaxInWindow(const std::vector<int>& nums, int winsize);

template <typename T>
class QueueWithMax {
   public:
    QueueWithMax() {}
    ~QueueWithMax() = default;

    void push_back(T number) {
        dataQueue_.emplace_back(number, index_);
        while (!maxQueue_.empty() && number > maxQueue_.back().number) {
            maxQueue_.pop_back();
        }
        maxQueue_.emplace_back(number, index_);
        ++index_;
    }

    T pop_front() {
        if (dataQueue_.empty()) {
            throw std::runtime_error("emtpy queue");
        }
        auto front = dataQueue_.front();
        dataQueue_.pop_front();
        if (front.index == maxQueue_.front().index) {
            maxQueue_.pop_front();
        }
        return front.number;
    }

    T max() const {
        if (maxQueue_.empty()) {
            throw std::runtime_error("emtpy queue");
        }
        return maxQueue_.front().number;
    }

   private:
    struct InternalData {
        T number;
        int index;

        InternalData(T number, int index) : number(number), index(index) {}
    };

    std::deque<InternalData> dataQueue_;
    std::deque<InternalData> maxQueue_;
    int index_ = 0;
};
