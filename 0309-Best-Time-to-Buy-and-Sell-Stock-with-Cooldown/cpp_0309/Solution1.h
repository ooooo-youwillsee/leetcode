//
// Created by ooooo on 2020/2/25.
//
#ifndef CPP_0309__SOLUTION1_H_
#define CPP_0309__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 第 i 天， j (0：不持有一股， 1：持有一股)
 *
 *  dp[i][0] = max(dp[i-1][0], dp[i-1][1] + p)
 *  dp[i][1] = max(dp[i-1][1], dp[i-2][0] - p)
 */
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = INT_MIN;
    for (int i = 0; i < n; ++i) {
      int j = i + 1, p = prices[i];
      dp[j][0] = max(dp[j - 1][0], dp[j - 1][1] + p);
      dp[j][1] = max(dp[j - 1][1], dp[max(j - 2, 0)][0] - p);
    }
    return dp[n][0];
  }
};

#endif //CPP_0309__SOLUTION1_H_
