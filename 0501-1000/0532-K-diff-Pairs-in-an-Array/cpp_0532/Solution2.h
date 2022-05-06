//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0532_SOLUTION2_H
#define CPP_0532_SOLUTION2_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * k=0, map
 */
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        int ans = 0;
        if (k == 0) {
            unordered_map<int, int> m;
            for (auto &num: nums) {
                if (m.count(num)) m[num] += 1;
                else m[num] = 1;
            }
            for (auto &entry: m) {
                if (entry.second >= 2) ans++;
            }
            return ans;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size() - 1; ++j) {
            for (int i = j + 1; i < nums.size(); ++i) {
                int diff = nums[i] - nums[j];
                if (diff == k) ans++;
                else if (diff > k) break;
            }
        }
        return ans;
    }
};

#endif //CPP_0532_SOLUTION2_H
