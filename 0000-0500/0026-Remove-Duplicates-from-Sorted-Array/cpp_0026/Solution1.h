//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0026_SOLUTION1_H
#define CPP_0026_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] == nums[i]) continue;
            i++;
            nums[i] = nums[j];
        }
        return i + 1;
    }
};

#endif //CPP_0026_SOLUTION1_H
