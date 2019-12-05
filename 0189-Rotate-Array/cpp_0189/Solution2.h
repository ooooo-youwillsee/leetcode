//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0189_SOLUTION2_H
#define CPP_0189_SOLUTION2_H


#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() == 0) return;
        k %= nums.size();
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int j = (i + k) % nums.size();
            res[j] = nums[i];
        }
        for (int l = 0; l < res.size(); ++l) {
            nums[l] = res[l];
        }
    }

};

#endif //CPP_0189_SOLUTION2_H
