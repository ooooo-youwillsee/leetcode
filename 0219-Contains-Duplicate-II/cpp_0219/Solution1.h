//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0219_SOLUTION1_H
#define CPP_0219_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 存在 索引差为k 就返回true
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (m.count(nums[i]) && i - m[nums[i]] <= k) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

#endif //CPP_0219_SOLUTION1_H
