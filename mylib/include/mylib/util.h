#ifndef MYLIB_UTIL_H
#define MYLIB_UTIL_H

#pragma once

#include <functional>
#include "mylib/ostream_op.h"

namespace mylib {

template <typename T>
using deleted_unique_ptr = std::unique_ptr<T, std::function<void(T *)>>;

template <typename T>
deleted_unique_ptr<T> make_deleted_unique(T *t,
                                          std::function<void(T *)> deleter) {
    return deleted_unique_ptr<T>(t, deleter);
}

// 用于释放资源
class Defer {
   public:
    template <typename F, typename... Args>
    Defer(F fn, Args &&... args)
        : fn_(std::bind(std::forward<F>(fn), std::forward<Args>(args)...)) {}

    ~Defer() { fn_(); }

   private:
    std::function<void(void)> fn_;
};

// T could be: int* or std::vector<int>
template <typename T>
std::string stringify(const T &A, int N) {
    std::ostringstream oss;
    oss << "[";
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            oss << ",";
        }
        oss << A[i];
    }
    oss << "]";
    return oss.str();
}

template <typename T>
std::string stringify(const T &A) {
    return stringify<T>(std::forward<const T &>(A), A.size());
}

// https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf/2342176
template <typename... Args>
std::string string_format(const std::string &format, Args... args) {
    size_t size = std::snprintf(nullptr, 0, format.c_str(), args...) +
                  1;  // Extra space for '\0'
    std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(),
                       buf.get() + size - 1);  // We don't want the '\0' inside
}

}  // namespace mylib

#endif  // MYLIB_UTIL_H