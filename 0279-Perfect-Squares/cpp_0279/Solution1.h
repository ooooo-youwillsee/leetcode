//
// Created by ooooo on 2020/2/23.
//
#ifndef CPP_0279__SOLUTION1_H_
#define CPP_0279__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * dfs timeout
 */
class Solution {
 public:

  void dfs(int n, int count) {
    if (n == 0) {
      ans = min(ans, count);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > n) continue;
      dfs(n - nums[i], count + 1);
    }
  }

  vector<int> nums;
  int ans = INT_MAX;

  int numSquares(int n) {
    for (int i = int(sqrt(n)); i >= 1; --i) {
      nums.push_back(i * i);
    }
    dfs(n, 0);
    return ans;
  }
};

#endif //CPP_0279__SOLUTION1_H_
