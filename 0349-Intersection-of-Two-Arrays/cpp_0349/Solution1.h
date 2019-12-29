//
// Created by ooooo on 2019/12/29.
//
#ifndef CPP_0349_SOLUTION1_H
#define CPP_0349_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set(nums1.size());
        for (const auto &num : nums1) {
            set.insert(num);
        }

        vector<int> res;
        for (const auto &num : nums2) {
            if (set.find(num) != set.end()) {
                set.erase(num);
                res.push_back(num);
            }
        }

        return res;
    }
};


#endif //CPP_0349_SOLUTION1_H
