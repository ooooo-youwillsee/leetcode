//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0532_SOLUTION1_H
#define CPP_0532_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 暴力 超时
 */
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        unordered_set<string> ans;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int max, min;
                if (nums[i] > nums[j]) {
                    max = nums[i];
                    min = nums[j];
                } else {
                    max = nums[j];
                    min = nums[i];
                }
                if (max - min == k) ans.insert(to_string(min) + "#" + to_string(max));
            }
        }
        return ans.size();
    }
};

#endif //CPP_0532_SOLUTION1_H
