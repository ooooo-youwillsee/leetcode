//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0027_SOLUTION1_H
#define CPP_0027_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                // 不相等就直接赋值
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

#endif //CPP_0027_SOLUTION1_H
