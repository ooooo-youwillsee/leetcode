//
// Created by ooooo on 2020/2/26.
//
#ifndef CPP_0322__SOLUTION1_H_
#define CPP_0322__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * p = coins[j]  ==>  dp[i] =  min(dp[i],dp[i-p] + 1)
 */
class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < coins.size(); ++j) {
        int k = i - coins[j];
        if (k >= 0) {
          dp[i] = min(dp[i], dp[k] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};

#endif //CPP_0322__SOLUTION1_H_
