//
// Created by ooooo on 2020/4/3.
//
#ifndef CPP_047__SOLUTION2_H_
#define CPP_047__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][j] = max( dp[i][j-1], dp[i-1][j] ) + grid[i][j]
 */
class Solution {
 public:

  int maxValue(vector<vector<int>> &grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i-1][j-1];
      }
    }
    return dp[m][n];
  }
};

#endif //CPP_047__SOLUTION2_H_
