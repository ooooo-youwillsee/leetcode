//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0217_SOLUTION1_H
#define CPP_0217_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

#endif //CPP_0217_SOLUTION1_H
