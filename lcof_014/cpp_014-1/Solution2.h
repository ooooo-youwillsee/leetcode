//
// Created by ooooo on 2020/3/11.
//
#ifndef CPP_014_1__SOLUTION2_H_
#define CPP_014_1__SOLUTION2_H_

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * dp[n] = max( dp[1] * dp[n-1], dp[2] * dp[n-2] )
 *
 * dp[n] 表示绳子长度为 n
 */
class Solution {
 public:

  int cuttingRope(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      // 不为 n 时，可以取整段
      dp[i] = i == n ? 1 : i;
      for (int j = 1; j <= i / 2; ++j) {
        dp[i] = max(dp[i], dp[j] * dp[i - j]);
      }
    }
    return dp[n];
  }
};

#endif //CPP_014_1__SOLUTION2_H_
