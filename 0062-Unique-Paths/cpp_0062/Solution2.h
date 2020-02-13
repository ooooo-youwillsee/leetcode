//
// Created by ooooo on 2020/2/13.
//
#ifndef CPP_0062__SOLUTION2_H_
#define CPP_0062__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[j] = dp[j] + dp[j-1]
 * 当前行和上一行的 dp
 */
class Solution {
 public:
  // n 行 m 列
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
  }
};

#endif //CPP_0062__SOLUTION2_H_
