//
// Created by ooooo on 2020/2/5.
//
#ifndef CPP_0746__SOLUTION1_H_
#define CPP_0746__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i] = min(dp[i-1] , dp[i-2]) + p (从第三个开始走)
 */
class Solution {
 public:

  int minCost(vector<int> &cost, int start, int end) {
    vector<int> dp(end - start + 3);
    int ans = INT_MAX;
    dp[start] = cost[start];
    dp[start + 1] = dp[start] + cost[start + 1];
    for (int i = start + 2; i <= end; ++i) {
      int p = cost[i];
      dp[i] = min(dp[i - 1], dp[i - 2]) + p;
      if (i >= end - 1) {
        ans = min(ans, dp[i]);
      }
    }
    return ans;
  }

  int minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    int end = cost.size() - 1;
    return min(minCost(cost, 0, end), minCost(cost, 1, end));
  }
};

#endif //CPP_0746__SOLUTION1_H_
