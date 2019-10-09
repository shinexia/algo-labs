#ifndef MYLIB_UTIL_H
#define MYLIB_UTIL_H

#pragma once

#include <functional>
#include <memory>
#include <string>
#include <sstream>

namespace mylib {

template <typename T>
using deleted_unique_ptr = std::unique_ptr<T, std::function<void(T*)>>;

template <typename T>
deleted_unique_ptr<T> make_deleted_unique(T* t,
                                          std::function<void(T*)> deleter) {
    return deleted_unique_ptr<T>(t, deleter);
}

template <typename T>
std::string stringify(const T A, int N) {
  std::ostringstream oss;
  oss << "[";
  for (int i=0; i<N; i++) {
    if (i != 0) {
      oss << ",";
    }
    oss << A[i];
  }
  oss << "]";
  return oss.str();
}

}  // namespace mylib

#endif  // MYLIB_UTIL_H