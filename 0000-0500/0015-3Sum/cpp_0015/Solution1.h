//
// Created by ooooo on 2019/10/31.
//
#ifndef CPP_0015_SOLUTION1_H
#define CPP_0015_SOLUTION1_H

#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        
        set<vector<int>> set;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            map<int, bool> map;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (map.find(-nums[i] - nums[j]) != map.end()) {
                    vector<int> vec = {nums[i], nums[j], -nums[i] - nums[j]};
                    set.insert(vec);
                }
                map[nums[j]] = true;
            }
        }

        for (auto item : set) {
            result.push_back(item);
        }
        return result;
    }
};

#endif //CPP_0015_SOLUTION1_H
