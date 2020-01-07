//
// Created by ooooo on 2020/1/7.
//
#ifndef CPP_0125_SOLUTION1_H
#define CPP_0125_SOLUTION1_H

#include <iostream>

using namespace std;


class Solution {
public:

    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int left = 0, right = s.size() - 1;
        while (left < right) {
            int a = tolower(s[left]);
            int b = tolower(s[right]);
            while (right > left && !isdigit(a) && !isalpha(a)) {
                left++;
                a = tolower(s[left]);
            }
            while (right > left && !isdigit(b) && !isalpha(b)) {
                right--;
                b = tolower(s[right]);
            }

            if (a == b) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};

#endif //CPP_0125_SOLUTION1_H
