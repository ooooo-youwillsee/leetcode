//
// Created by ooooo on 2019/12/30.
//
#ifndef CPP_0136_SOLUTION1_H
#define CPP_0136_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (auto num : nums) {
            if (map.find(num) == map.end()) {
                map[num] = 1;
            } else {
                map[num] += 1;
            }
        }

        for (auto item : map) {
            if (item.second == 1) {
                return item.first;
            }
        }
        return 0;
    }
};

#endif //CPP_0136_SOLUTION1_H
