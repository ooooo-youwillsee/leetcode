//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0035_SOLUTION2_H
#define CPP_0035_SOLUTION2_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (true) {
            int mid = left + (right - left + 1) / 2;
            if (left > right || nums[mid] == target) {
                ans = mid;
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

#endif //CPP_0035_SOLUTION2_H
