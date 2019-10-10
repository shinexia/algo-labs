#ifndef MYLIB_STREAMUTIL_H
#define MYLIB_STREAMUTIL_H

#pragma once

#include <list>
#include <map>
#include <memory>
#include <ostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

template <typename K, typename V>
inline std::ostream &operator<<(std::ostream &oss, const std::pair<K, V> &val) {
    oss << val.first << ":" << val.second;
    return oss;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &oss, const std::vector<T> &val) {
    oss << "[";
    for (auto iter = val.begin(); iter != val.end(); ++iter) {
        if (iter != val.begin()) {
            oss << ",";
        }
        oss << *iter;
    }
    oss << "]";
    return oss;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &oss, const std::list<T> &val) {
    oss << "[";
    for (auto iter = val.begin(); iter != val.end(); ++iter) {
        if (iter != val.begin()) {
            oss << ",";
        }
        oss << *iter;
    }
    oss << "]";
    return oss;
}

template <typename K, typename V>
inline std::ostream &operator<<(std::ostream &oss, const std::map<K, V> &val) {
    oss << "{";
    for (auto iter = val.begin(); iter != val.end(); ++iter) {
        if (iter != val.begin()) {
            oss << ",";
        }
        oss << iter->first << ":" << iter->second;
    }
    oss << "}";
    return oss;
}

inline std::ostream &operator<<(std::ostream &oss,
                                const std::ostringstream &val) {
    oss << val;
    return oss;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &oss,
                                const std::shared_ptr<T> &val) {
    if (val == nullptr) {
        oss << "<null>";
    } else {
        oss << *val;
    }
    return oss;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &oss,
                                const std::unique_ptr<T> &val) {
    if (val == nullptr) {
        oss << "<null>";
    } else {
        oss << *val;
    }
    return oss;
}

#endif  // MYLIB_STREAMUTIL_H