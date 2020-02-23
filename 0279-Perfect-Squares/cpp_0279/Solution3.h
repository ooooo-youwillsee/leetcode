//
// Created by ooooo on 2020/2/23.
//
#ifndef CPP_0279__SOLUTION3_H_
#define CPP_0279__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/**
 * dp[i] = min(dp[i], dp[i - j*j] + 1 )
 */
class Solution {
 public:

  int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      dp[i] = i; // 最多就是所有的 1 相加
      for (int j = 1; i - j * j >= 0; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

#endif //CPP_0279__SOLUTION3_H_
