//
// Created by Shine Xia on 2019/2/17.
//

#ifndef ALGORITHM_LABS_PALINDROME_NUMBER_H
#define ALGORITHM_LABS_PALINDROME_NUMBER_H

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || (x % 10 == 0)) {
            return false;
        }
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        return x == rev || x == rev / 10;
    }
};


#endif //ALGORITHM_LABS_PALINDROME_NUMBER_H
