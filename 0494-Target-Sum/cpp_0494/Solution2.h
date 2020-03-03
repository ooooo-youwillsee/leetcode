//
// Created by ooooo on 2020/3/3.
//
#ifndef CPP_0494__SOLUTION2_H_
#define CPP_0494__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]
 *
 * 背包问题
 *
 * j 最小值为 -sum,所以 j-nums[i] => 最小值为 -sum-nums[i]
 */
class Solution {
 public:

  int findTargetSumWays(vector<int> &nums, int S) {
    int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
    int t = 2 * sum + 1;
    // 绝对值范围超过了sum的绝对值范围则无法得到
    if (S > sum) return 0;
    vector<vector<int>> dp(n, vector<int>(t));
    if (nums[0] == 0) {
      // +0 或者 -0
      dp[0][sum] = 2;
    } else {
      dp[0][-nums[0] + sum] = 1;
      dp[0][+nums[0] + sum] = 1;
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < t; ++j) {
        // j 加上偏移量 sum
        int l = (j - nums[i]) >= 0 ? j - nums[i] : 0;
        int r = (j + nums[i]) < t ? j + nums[i] : 0;
        dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
      }
    }
    return dp[n - 1][S + sum];
  }
};
#endif //CPP_0494__SOLUTION2_H_
