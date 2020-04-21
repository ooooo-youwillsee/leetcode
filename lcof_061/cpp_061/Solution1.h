//
// Created by ooooo on 2020/4/21.
//
#ifndef CPP_061__SOLUTION1_H_
#define CPP_061__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isStraight(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int count_0 = 0, len = nums.size();
    for (int i = 0; i < len && nums[i] == 0; ++i) {
      count_0++;
    }
    int gap = 0;
    for (int j = count_0 + 1; j < len; ++j) {
      if (nums[j] == nums[j - 1]) return false;
      gap += nums[j] - nums[j - 1] - 1;
    }
    return gap <= count_0;
  }
};

#endif //CPP_061__SOLUTION1_H_
