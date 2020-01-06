//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0066_SOLUTION1_H
#define CPP_0066_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty()) return {};

        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] = digits[i] + 1;
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                return digits;
            }
        }
        //digits.insert(digits.begin(), 1);
        vector<int> ans(digits.size() + 1, 0);
        ans[0] = 1;
        return ans;
    }
};

#endif //CPP_0066_SOLUTION1_H
