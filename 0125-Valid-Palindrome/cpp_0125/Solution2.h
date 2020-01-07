//
// Created by ooooo on 2020/1/7.
//
#ifndef CPP_0125_SOLUTION2_H
#define CPP_0125_SOLUTION2_H


#include <iostream>

using namespace std;


class Solution {
public:

    bool isPalindrome(string s) {
        string ans = "";
        for (auto &c: s) {
            if (isalnum(c)) ans += tolower(c);
        }
        string source = ans;
        reverse(ans.begin(), ans.end());
        return source == ans;
    }
};

#endif //CPP_0125_SOLUTION2_H
