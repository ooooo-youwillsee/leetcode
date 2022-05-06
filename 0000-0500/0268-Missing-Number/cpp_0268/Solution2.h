//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0268_SOLUTION2_H
#define CPP_0268_SOLUTION2_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int sum = 0;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            sum += (i - nums[i]);
        }
        return sum + nums.size();
    }
};

#endif //CPP_0268_SOLUTION2_H
