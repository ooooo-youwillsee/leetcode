//
// Created by ooooo on 6/15/2021.
//

#ifndef CPP_1449_SOLUTION1_H
#define CPP_1449_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &cost, int target) {
      int n = cost.size();
      // 恰好为target，所以初始化为 INT_MIN
      vector<int> dp(target + 1, INT_MIN);
      dp[0] = 0;

      for (int i = 0; i < n; i++) {
        for (int j = cost[i]; j <= target; j++) {
          // 不能用二维数组，如果用的话，需要遍历i之前所有的状态
          dp[j] = max(dp[j], dp[j - cost[i]] + 1);
        }
      }
      if (dp[target] < 0) {
        return "0";
      }
      string ans = "";
      for (int i = n - 1; i >= 0; i--) {
        while (target >= cost[i] && dp[target - cost[i]] == dp[target] - 1) {
          ans += '0' + i + 1;
          target -= cost[i];
        }
      }
      return ans;
    }
};

#endif //CPP_1449_SOLUTION1_H
