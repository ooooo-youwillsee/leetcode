//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0035_SOLUTION1_H
#define CPP_0035_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty() || target < nums[0]) return 0;
        if (target > nums[nums.size() - 1]) return nums.size();
        int ans = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == target) {
                ans = i;
                break;
            } else if (target > nums[i] && target < nums[i + 1]) {
                ans = i + 1;
                break;
            }
        }
        return ans == -1 ? nums.size() - 1 : ans;
    }
};

#endif //CPP_0035_SOLUTION1_H
