//
// Created by ooooo on 6/16/2021.
//

#ifndef CPP_0877_SOLUTION1_H
#define CPP_0877_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int> &piles) {
      int n = piles.size();
      // dp[i][j] 表示 i 到 j 之间的差值
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
          int a = piles[i] - (i + 1 >= n ? 0 : dp[i + 1][j]);
          int b = piles[j] - (j - 1 < 0 ? 0 : dp[i][j - 1]);
          dp[i][j] = max(a, b);
        }
      }
      return dp[0][n - 1] > 0;
    }
};

#endif //CPP_0877_SOLUTION1_H
