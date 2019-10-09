#include "solution.h"
#include "mylib/util.h"

int longestSubstringWithoutDuplication(const std::string& str) {
    int* positions = new int[26];
    mylib::deleted_unique_ptr<int> p_deleter(positions,
                                             [](int* p) { delete[] p; });
    for (int i = 0; i < 26; ++i) {
        positions[i] = -1;
    }
    int maxLength = 0;
    int curLength = 0;
    for (int i = 0; i < str.length(); ++i) {
        char c = str[i];
        int ci = c - 'a';
        int pos = positions[ci];
        if (pos < 0 || (i - pos) > curLength) {
            ++curLength;
        } else {
            curLength = i - pos;
        }
        if (curLength > maxLength) {
            maxLength = curLength;
        }
        positions[ci] = i;
    }
    return maxLength;
}
