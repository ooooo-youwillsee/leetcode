//
// Created by ooooo on 2020/2/26.
//
#ifndef CPP_0322__SOLUTION3_H_
#define CPP_0322__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * bfs timeout
 */
class Solution {
 public:

  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0) return 0;
    sort(coins.begin(), coins.end());
    queue<int> q;
    q.push(amount);
    int level = 0;
    while (!q.empty()) {
      level += 1;
      for (int i = 0, len = q.size(); i < len; ++i) {
        auto n = q.front();
        q.pop();
        for (int j = 0; j < coins.size() && n >= coins[j]; ++j) {
          int k = n - coins[j];
          if (k == 0) return level;
          else {
            q.push(k);
          }
        }
      }
    }
    return -1;
  }
};

#endif //CPP_0322__SOLUTION3_H_
