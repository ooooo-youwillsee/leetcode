//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0268_SOLUTION3_H
#define CPP_0268_SOLUTION3_H


#include <iostream>
#include <vector>

using namespace std;

/**
 * a ^ 0  = a
 * a ^ a  = 0
 */
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int num = nums.size();
        for (int i = 0, len = nums.size(); i < len; ++i) {
            num ^= i ^ nums[i];
        }
        return num;
    }
};


#endif //CPP_0268_SOLUTION3_H
