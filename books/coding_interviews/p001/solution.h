#ifndef P001_SOLUTION_H
#define P001_SOLUTION_H

#include <cstring>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

class CMyString {
   public:
    CMyString(char* data = nullptr) : data_(data) {}
    CMyString(const char* data) { *this = data; }
    CMyString(const CMyString& other) { *this = other; }
    CMyString(CMyString&& other) { *this = std::move(other); }

    ~CMyString() { delete[] data_; }

    CMyString& operator=(const char* data) noexcept {
        auto len = strlen(data);
        std::unique_ptr<char> buf(new char[len + 1]);
        strcpy(buf.get(), data);
        buf.get()[len] = '\0';
        data_ = buf.release();
        return *this;
    }

    CMyString& operator=(const CMyString& other) noexcept {
        auto len = strlen(other.data_);
        std::unique_ptr<char> buf(new char[len + 1]);
        strcpy(buf.get(), other.data_);
        buf.get()[len] = '\0';
        data_ = buf.release();
        return *this;
    }

    CMyString& operator=(CMyString&& other) noexcept {
        char* t = data_;
        data_ = other.data_;
        other.data_ = t;
        return *this;
    }

    std::string str() const {
        if (!data_) {
            return std::string();
        }
        return std::string(data_);
    }

    const char* data() const { return data_; }

   private:
    char* data_ = nullptr;
};

inline std::ostream& operator<<(std::ostream& os, const CMyString& str) {
    os << str.str();
    return os;
}

inline bool operator==(const CMyString& str, const char* b) {
    const char* a = str.data();
    if (a == b) {
        return true;
    }
    if (!a) {
        return b == nullptr || b[0] == '\0';
    }
    if (!b) {
        return a == nullptr || a[0] == '\0';
    }
    return !strcmp(a, b);
}

inline bool operator==(const CMyString& str, const CMyString& other) {
    return str == other.data();
}

inline bool operator==(const CMyString& str, const std::string& other) {
    return str == other.c_str();
}

inline bool operator!=(const CMyString& str, const char* b) {
    return !(str == b);
}

inline bool operator!=(const CMyString& str, const CMyString& b) {
    return !(str == b);
}

inline bool operator!=(const CMyString& str, const std::string& b) {
    return !(str == b);
}

#endif  // P001_SOLUTION_H
