//
// Created by ooooo on 2020/2/13.
//
#ifndef CPP_0062__SOLUTION1_H_
#define CPP_0062__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][j] = dp[i][j-1] + dp[i-1][j]
 */
class Solution {
 public:
  // n 行 m 列
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(m, 1));
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[n - 1][m - 1];
  }
};

#endif //CPP_0062__SOLUTION1_H_
