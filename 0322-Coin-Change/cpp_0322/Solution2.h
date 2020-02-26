//
// Created by ooooo on 2020/2/26.
//
#ifndef CPP_0322__SOLUTION2_H_
#define CPP_0322__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * dfs timeout
 */
class Solution {
 public:

  vector<int> coins;
  unordered_map<int, int> memo;
  int ans = INT_MAX;

  void dfs(int amount, int count) {
    if (amount == 0) {
      ans = min(ans, count);
      return;
    }
    for (int i = 0; i < coins.size() && amount >= coins[i]; ++i) {
      dfs(amount - coins[i], count + 1);
    }
  }

  int coinChange(vector<int> &coins, int amount) {
    sort(coins.begin(), coins.end());
    this->coins = coins;
    dfs(amount, 0);
    return ans == INT_MAX ? -1 : ans;
  }
};

#endif //CPP_0322__SOLUTION2_H_
