//
// Created by ooooo on 2019/10/31.
//
#ifndef CPP_0015_SOLUTION1_H
#define CPP_0015_SOLUTION1_H

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[0] > 0) break;
            if (nums[i] == nums[i - 1] && i > 0) continue;
            set<int> set;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == nums[j - 1] && j > 0) continue;
                set.insert(nums[j]);
                if (set.find(-nums[i] - nums[j]) != set.end()) {
                    vector<int> vec = {nums[i], nums[j], -nums[i] - nums[j]};
                    result.push_back(vec);
                }
            }
        }

        return result;
    }
};

#endif //CPP_0015_SOLUTION1_H
