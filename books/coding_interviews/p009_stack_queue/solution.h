#pragma once

#include <stdexcept>
#include <stack>

template <typename T>
class CQueue {
   public:
    CQueue() : stack1(), stack2() {}

    ~CQueue(){};

    void appendTail(const T& t) { stack2.emplace(t); }

    T deleteHead() {
        if (!stack1.empty()) {
            auto t = std::move(stack1.top());
            stack1.pop();
            return t;
        }
        if (stack2.empty()) {
            throw std::runtime_error("queue is empty");
        }
        while (stack2.size() > 1) {
            stack1.push(std::move(stack2.top()));
            stack2.pop();
        }
        T t = std::move(stack2.top());
        stack2.pop();
        return t;
    }

   private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};
