//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0169_SOLUTION1_H
#define CPP_0169_SOLUTION1_H

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        map<int, int> m;
        int size = nums.size();
        for (auto i: nums) {
            map<int, int>::iterator it = m.find(i);
            if (it == m.end()) {
                m[i] = 1;
            } else {
                m[i] = it->second + 1;
            }
            if (m[i] > size / 2) {
                return i;
            }
        }
        return 0;
    }
};

#endif //CPP_0169_SOLUTION1_H
