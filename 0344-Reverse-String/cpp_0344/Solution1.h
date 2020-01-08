//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0344_SOLUTION1_H
#define CPP_0344_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseString(vector<char> &s) {
        if (s.size() <= 1) return;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};

#endif //CPP_0344_SOLUTION1_H
