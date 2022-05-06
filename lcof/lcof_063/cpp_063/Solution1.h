//
// Created by ooooo on 2020/4/24.
//
#ifndef CPP_063__SOLUTION1_H_
#define CPP_063__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    dp[0][1][0] = INT_MIN;
    dp[0][1][1] = INT_MIN;
    dp[0][0][1] = INT_MIN;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int p = prices[i];
      dp[i + 1][0][0] = dp[i][0][0];
      dp[i + 1][1][0] = INT_MIN;
      dp[i + 1][1][1] = max(dp[i][1][1], dp[i][0][0] - p);
      dp[i + 1][0][1] = max(dp[i][0][1], dp[i][1][1] + p);
      ans = max(ans, dp[i + 1][0][1]);
    }
    return ans;
  }
};

#endif //CPP_063__SOLUTION1_H_
