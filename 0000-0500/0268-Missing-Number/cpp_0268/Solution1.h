//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0268_SOLUTION1_H
#define CPP_0268_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s;
        for (int i = 0, len = nums.size(); i <= len; ++i) {
            s.insert(i);
        }
        for (auto &num: nums) {
            if (s.count(num)) s.erase(num);
        }

        return *begin(s);
    }
};

#endif //CPP_0268_SOLUTION1_H
