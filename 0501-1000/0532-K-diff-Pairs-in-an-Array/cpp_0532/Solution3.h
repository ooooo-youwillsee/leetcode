//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0532_SOLUTION3_H
#define CPP_0532_SOLUTION3_H


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 *
 */
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (nums.empty() || k < 0) return 0;
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
        } else {
            unordered_set<string> set;
            unordered_set<int> s;
            for (auto &num: nums) {
                if (s.count(num + k)) set.insert(to_string(num) + "#" + to_string(num + k));
                if (s.count(num - k)) set.insert(to_string(num - k) + "#" + to_string(num));
                s.insert(num);
            }
            ans = set.size();
        }
        return ans;
    }
};

#endif //CPP_0532_SOLUTION3_H
