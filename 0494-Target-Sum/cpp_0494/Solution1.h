//
// Created by ooooo on 2020/3/3.
//
#ifndef CPP_0494__SOLUTION1_H_
#define CPP_0494__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dfs
 */
class Solution {
 public:

  void dfs(int i, int sum) {
    if (i == nums.size()) {
      if (sum == S) {
        count++;
      }
      return;
    }
    dfs(i + 1, sum - nums[i]);
    dfs(i + 1, sum + nums[i]);
  }
  vector<int> nums;
  int S, count = 0;

  int findTargetSumWays(vector<int> &nums, int S) {
    this->nums = nums;
    this->S = S;
    dfs(0, 0);
    return count;
  }
};

#endif //CPP_0494__SOLUTION1_H_
