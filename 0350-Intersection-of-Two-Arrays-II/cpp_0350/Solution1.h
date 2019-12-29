//
// Created by ooooo on 2019/12/29.
//
#ifndef CPP_0350_SOLUTION1_H
#define CPP_0350_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;
        for (const auto &num : nums1) {
            if (map.find(num) == map.end()) {
                map[num] = 1;
            } else {
                map[num] = map[num] + 1;
            }
        }

        vector<int> res;
        for (const auto &num : nums2) {
            if (map.find(num) != map.end()) {
                res.push_back(num);
                if (map[num] == 1) {
                    map.erase(num);
                } else {
                    map[num] -= 1;
                }
            }
        }

        return res;
    }
};

#endif //CPP_0350_SOLUTION1_H
