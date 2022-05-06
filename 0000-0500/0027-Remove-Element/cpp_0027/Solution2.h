//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0027_SOLUTION2_H
#define CPP_0027_SOLUTION2_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.size() < 1) return 0;
        int i = 0, j = nums.size() - 1;
        while (true) {
            // 先判断i和j是否越界
            while (i < nums.size() && nums[i] != val) i++;
            while (j >= 0 && nums[j] == val) j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return i;
    }
};

#endif //CPP_0027_SOLUTION2_H
