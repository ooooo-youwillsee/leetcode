//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0018_SOLUTION1_H
#define CPP_0018_SOLUTION1_H

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/**
 * 两层循环， 加上双指针
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;

        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> set;

        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int k = j + 1;
                int p = nums.size() - 1;
                while (k < p) {
                    int n = nums[i] + nums[j] + nums[k] + nums[p];
                    if (n < target) {
                        k += 1;
                    } else if (n > target) {
                        p -= 1;
                    } else {
                        vector<int> vec = {nums[i], nums[j], nums[k], nums[p]};
                        set.insert(vec);
                        k += 1;
                        p -= 1;
                    }
                }
            }
        }

        for (auto item : set) {
            res.push_back(item);
        }

        return res;
    }
};

#endif //CPP_0018_SOLUTION1_H
