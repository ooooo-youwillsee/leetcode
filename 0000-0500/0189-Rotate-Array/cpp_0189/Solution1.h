//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0189_SOLUTION1_H
#define CPP_0189_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    // 每次移动一个， 总共k次
    void rotate(vector<int> &nums, int k) {
        if (nums.size() == 0) return;
        k %= nums.size();
        for (int i = 0; i < k; i++) {
            int temp = nums[nums.size() - 1];
            for (int j = nums.size() - 1; j > 0; --j) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
        }
    }

};

#endif //CPP_0189_SOLUTION1_H
