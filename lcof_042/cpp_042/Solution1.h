//
// Created by ooooo on 2020/3/27.
//
#ifndef CPP_042__SOLUTION1_H_
#define CPP_042__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size(), ans = nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      if (dp[i - 1] < 0) dp[i] = nums[i];
      else dp[i] = dp[i - 1] + nums[i];
      ans = std::max(ans, dp[i]);
    }
    return ans;
  }
};

#endif //CPP_042__SOLUTION1_H_
