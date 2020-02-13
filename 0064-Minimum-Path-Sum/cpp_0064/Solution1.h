//
// Created by ooooo on 2020/2/13.
//
#ifndef CPP_0064__SOLUTION1_H_
#define CPP_0064__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][j] = cur_num + min(dp[i-1][j] + dp[i][j-1])
 */
class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; ++i) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[m - 1][n - 1];
  }
};
#endif //CPP_0064__SOLUTION1_H_
