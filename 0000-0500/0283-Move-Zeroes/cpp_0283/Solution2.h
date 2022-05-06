//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0283_SOLUTION2_H
#define CPP_0283_SOLUTION2_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() <= 1) return;
        int count = 0, j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            } else {
                count++;
            }
        }
        for (int k = nums.size() - 1; count--; --k) {
            nums[k] = 0;
        }
    }
};

#endif //CPP_0283_SOLUTION2_H
