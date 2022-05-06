//
// Created by ooooo on 2020/2/29.
//
#ifndef CPP_0416__SOLUTION2_H_
#define CPP_0416__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
 *
 * 背包问题
 */
class Solution {
 public:

  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int n = nums.size(), target = sum / 2;
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    dp[0][0] = true;
    if (nums[0] <= target) {
      dp[0][nums[0]] = true;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= target; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (nums[i] <= j) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        }
      }
      if (dp[i][target]) return true;
    }
    return dp[n - 1][target];
  }
};

#endif //CPP_0416__SOLUTION2_H_
