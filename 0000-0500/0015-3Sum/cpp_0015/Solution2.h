//
// Created by ooooo on 2019/10/31.
//
#ifndef CPP_0015_SOLUTION2_H
#define CPP_0015_SOLUTION2_H

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        set<vector<int>> set;

        for (int i = 0, len = nums.size(); i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int s = i + 1;
            int e = len - 1;

            while (s < e) {
                int n = nums[s] + nums[e] + nums[i];
                if (n < 0) {
                    s += 1;
                } else if (n > 0) {
                    e -= 1;
                } else {
                    vector<int> vec = {nums[i], nums[s], nums[e]};
                    set.insert(vec);
                    s += 1;
                    e -= 1;
                }
            }

        }
        for (auto item : set) {
            res.push_back(item);
        }

        return res;
    }
};


#endif //CPP_0015_SOLUTION2_H
