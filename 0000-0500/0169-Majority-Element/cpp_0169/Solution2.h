//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0169_SOLUTION2_H
#define CPP_0169_SOLUTION2_H


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        for (int i = 0; i < size; i++) {
            if (size / 2 < size && nums[i] == nums[size / 2]) {
                return nums[i];
            }
        }
        return 0;
    }
};

#endif //CPP_0169_SOLUTION2_H
