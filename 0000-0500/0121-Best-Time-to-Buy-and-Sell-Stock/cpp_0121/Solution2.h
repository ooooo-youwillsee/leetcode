//
// Created by ooooo on 2020/2/5.
//
#ifndef CPP_0121__SOLUTION2_H_
#define CPP_0121__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 动态规划
 *
 * i: 第几天， k：第几次交易
 * dp[i][k][0] = max(dp[i-1][k][1] + p , dp[i-1][k][0])
 * dp[i][k][1] = max(dp[i-1][k-1][0] - p , dp[i-1][k][1])
 */
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    dp[0][1][1] = INT_MIN;
    for (int i = 0; i < prices.size() + 1; ++i) {
      dp[i][0][1] = INT_MIN;
    }

    for (int j = 0; j < prices.size(); ++j) {
      int i = j + 1, p = prices[j];
      for (int k = 1; k <= 1; ++k) {
        dp[i][k][0] = max(dp[i - 1][k][1] + p, dp[i - 1][k][0]);
        dp[i][k][1] = max(dp[i - 1][k - 1][0] - p, dp[i - 1][k][1]);
        ans = max(dp[i][k][0], ans);
      }
    }
    return dp[prices.size()][1][0];
  }

};

#endif //CPP_0121__SOLUTION2_H_
