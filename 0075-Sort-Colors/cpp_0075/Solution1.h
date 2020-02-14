//
// Created by ooooo on 2020/2/14.
//
#ifndef CPP_0075__SOLUTION1_H_
#define CPP_0075__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 计数
 */
class Solution {
 public:

  void fill(vector<int> &nums, int start, int v, int count) {
    for (int i = start, c = 0; c < count; ++i, c++) {
      nums[i] = v;
    }
  }
  void sortColors(vector<int> &nums) {
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for (auto &num: nums) {
      if (num == 0) count_0++;
      else if (num == 1) count_1++;
      else count_2++;
    }
    fill(nums, 0, 0, count_0);
    fill(nums, count_0, 1, count_1);
    fill(nums, count_0 + count_1, 2, count_2);
  }
};

#endif //CPP_0075__SOLUTION1_H_
