//
// Created by ooooo on 2020/3/5.
//
#ifndef CPP_003__SOLUTION3_H_
#define CPP_003__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 抽屉原理
 */
class Solution {
 public:
  int findRepeatNumber(vector<int> &nums) {
    for (int i = 0, len = nums.size(); i < len;) {
      if (nums[i] == i) {
        i += 1;
      } else {
        if (nums[i] == nums[nums[i]]) return nums[i];
        swap(nums[i], nums[nums[i]]);
      }
    }
    return -1;
  }
};

#endif //CPP_003__SOLUTION3_H_
