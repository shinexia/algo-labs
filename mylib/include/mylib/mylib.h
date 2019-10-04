#ifndef MYLIB_MYLIB_H
#define MYLIB_MYLIB_H

#pragma once
#include <functional>
#include <memory>
#include <string>

namespace mylib {

template <typename T>
using deleted_unique_ptr = std::unique_ptr<T, std::function<void(T*)>>;

template <typename T>
deleted_unique_ptr<T> make_deleted_unique(T* t,
                                          std::function<void(T*)> deleter) {
    return deleted_unique_ptr<T>(t, deleter);
}

std::string stringify(const int A[], int N);

}  // namespace mylib

#endif  // MYLIB_MYLIB_H
