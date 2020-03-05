//
// Created by ooooo on 2020/3/5.
//
#ifndef CPP_003__SOLUTION2_H_
#define CPP_003__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * sort
 */
class Solution {
 public:
  int findRepeatNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0, len = nums.size() - 1; i < len; ++i) {
      if (nums[i] == nums[i + 1]) return nums[i];
    }
    return -1;
  }
};

#endif //CPP_003__SOLUTION2_H_
