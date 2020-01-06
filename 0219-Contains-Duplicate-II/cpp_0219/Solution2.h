//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0219_SOLUTION2_H
#define CPP_0219_SOLUTION2_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/**
 * 滑动窗口 (窗口大小为k)
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> s;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (s.count(nums[i])) return true;
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};


#endif //CPP_0219_SOLUTION2_H
