//
// Created by ooooo on 2020/4/20.
//
#ifndef CPP_060__SOLUTION1_H_
#define CPP_060__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  vector<double> twoSum(int n) {
    int max_count = 6; // 最大的点数
    vector<vector<int>> dp(n + 1, vector<int>(n * max_count + 1, 0));
    for (int j = 1; j <= max_count; ++j) dp[1][j] = 1;

    // i 表示几个骰子
    for (int i = 2; i <= n; ++i) {
      // j 表示可能的点数
      for (int j = i; j <= i * max_count; ++j) {
        for (int k = 1; k < j && k <= max_count; ++k) {
          dp[i][j] += dp[i - 1][j - k];
        }
      }
    }

    vector<double> ans;
    double total = pow(6, n);
    for (int i = n; i <= max_count * n; ++i) ans.push_back(dp[n][i] / total);
    return ans;
  }
};

#endif //CPP_060__SOLUTION1_H_
