#include "solution.h"
#include <cstring>
#include <memory>

CMyString::CMyString(const CMyString& str) : data_(nullptr) {
    auto len = strlen(str.data_);
    std::unique_ptr<char> buf(new char[len]);
    strcpy(buf.get(), str.data_);
    data_ = buf.get();
    buf.release();
}

CMyString::~CMyString() {
  if (data_) {
    delete []data_;
  }
}
