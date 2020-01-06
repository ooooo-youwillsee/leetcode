//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0283_SOLUTION1_H
#define CPP_0283_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() <= 1) return;
        int i = 0, j = 0;
        while (true) {
            while (i < nums.size() && nums[i] != 0) i++;
            while (j < nums.size() && nums[j] == 0) j++;
            if (i > j) {
                j++;
                continue;
            }
            if (j >= nums.size() || i >= nums.size()) break;
            swap(nums[i], nums[j]);
        }
    }
};

#endif //CPP_0283_SOLUTION1_H
