//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0532_SOLUTION4_H
#define CPP_0532_SOLUTION4_H


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
        unordered_set<int> set;
        unordered_set<int> s;
        for (auto &num: nums) {
            // 可以存入最小值，！！！
            if (s.count(num + k)) set.insert(num);
            if (s.count(num - k)) set.insert(num - k);
            s.insert(num);
        }

        return set.size();
    }

};

#endif //CPP_0532_SOLUTION4_H
