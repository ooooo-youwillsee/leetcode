//
// Created by ooooo on 6/14/2021.
//

#ifndef CPP_0879_SOLUTION1_H
#define CPP_0879_SOLUTION1_H

#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
      int m = profit.size();
      int mod = 1e9 + 7;
      int dp[m + 1][n + 1][minProfit + 1];
      memset(dp, 0, sizeof(dp));
      for (int i = 0; i <= n; i++) {
        dp[0][i][0] = 1;
      }
      for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
          for (int k = 0; k <= minProfit; k++) {
            dp[i + 1][j][k] = dp[i][j][k];
            if (j >= group[i]) {
              dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j - group[i]][max(0, k - profit[i])]) % mod;
            }
          }
        }
      }
      return dp[m][n][minProfit];
    }
};

#endif //CPP_0879_SOLUTION1_H
