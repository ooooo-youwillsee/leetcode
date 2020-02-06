//
// Created by ooooo on 2020/2/5.
//
#ifndef CPP_0746__SOLUTION2_H_
#define CPP_0746__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i] = min(dp[i-1] , dp[i-2]) + p
 */
class Solution {
 public:

  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size(), *dp = new int[n];
    dp[0] = cost[0], dp[1] = cost[1];
    for (int i = 2; i < n; ++i) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    // 倒数第二个可以直接跳两步
    return min(dp[n - 1], dp[n - 2]);
  }
};

#endif //CPP_0746__SOLUTION2_H_
