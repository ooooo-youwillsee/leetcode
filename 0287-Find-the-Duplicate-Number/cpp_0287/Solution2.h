//
// Created by ooooo on 2020/2/23.
//
#ifndef CPP_0287__SOLUTION2_H_
#define CPP_0287__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * sort
 */
class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1]) return nums[i];
    }
    return -1;
  }
};

#endif //CPP_0287__SOLUTION2_H_
