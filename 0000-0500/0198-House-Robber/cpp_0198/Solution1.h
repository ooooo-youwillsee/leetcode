//
// Created by ooooo on 2020/2/5.
//
#ifndef CPP_0198__SOLUTION1_H_
#define CPP_0198__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][1] = dp[i-1][0] + p
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] )
 */
class Solution {
 public:
  int rob(vector<int> &nums) {
    int ans = 0, n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int j = 0; j < n; ++j) {
      int i = j + 1, p = nums[j];
      dp[i][1] = dp[i - 1][0] + p;
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    return max(dp[n][1], dp[n][0]);
  }
};

#endif //CPP_0198__SOLUTION1_H_
