//
// Created by ooooo on 2019/12/19.
//
#ifndef CPP_0152_SOLUTION1_H
#define CPP_0152_SOLUTION1_H

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {

        int res = INT_MIN;
        int iMax = 1;
        int iMin = 1;
        for (const auto &num : nums) {
            if (num < 0) {
                int temp = iMax;
                iMax = iMin;
                iMin = temp;
            }
            iMax = max(iMax * num, num);
            iMin = min(iMin * num, num);
            res = max(res, iMax);
        }

        return res;
    }
};

#endif //CPP_0152_SOLUTION1_H
