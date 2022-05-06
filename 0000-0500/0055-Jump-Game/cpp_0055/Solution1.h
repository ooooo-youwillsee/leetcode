//
// Created by ooooo on 2020/2/12.
//
#ifndef CPP_0055__SOLUTION1_H_
#define CPP_0055__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 超时
 */
class Solution {
 public:
  bool canJump(vector<int> &nums) {
    vector<bool> dp(nums.size(), false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
      if (!dp[i]) return false;
      for (int j = 0; j <= nums[i]; ++j) {
        if (i + j >= nums.size() - 1) return true;
        dp[i + j] = true;
      }
    }
    return false;
  }
};

#endif //CPP_0055__SOLUTION1_H_
