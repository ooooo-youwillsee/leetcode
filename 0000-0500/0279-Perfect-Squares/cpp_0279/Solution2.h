//
// Created by ooooo on 2020/2/23.
//
#ifndef CPP_0279__SOLUTION2_H_
#define CPP_0279__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/**
 * dp[i] = min  (dp[i-1] + dp[1]), ( dp[i-2] + dp[2] ) ,,, (dp[0] + dp[i])
 * timeout
 */
class Solution {
 public:

  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    for (int i = int(sqrt(n)); i >= 1; --i) {
      int index = i * i;
      if (index == n) return 1;
      dp[index] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      if (dp[i] == 1) continue;
      for (int j = 1; j < i; ++j) {
        dp[i] = min(dp[i - j] + dp[j], dp[i]);
      }
    }

    return dp[n];
  }
};

#endif //CPP_0279__SOLUTION2_H_
