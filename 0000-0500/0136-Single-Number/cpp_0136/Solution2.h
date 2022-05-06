//
// Created by ooooo on 2019/12/30.
//
#ifndef CPP_0136_SOLUTION2_H
#define CPP_0136_SOLUTION2_H


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int a = 0;
        for (auto num: nums) {
            a ^= num;
        }
        return a;
    }
};

#endif //CPP_0136_SOLUTION2_H
