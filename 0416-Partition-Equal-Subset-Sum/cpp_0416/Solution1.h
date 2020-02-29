//
// Created by ooooo on 2020/2/29.
//
#ifndef CPP_0416__SOLUTION1_H_
#define CPP_0416__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * dfs timeout
 */
class Solution {
 public:

  bool dfs(int i, int left_remains, int right_remains) {
    if (left_remains == 0 || right_remains == 0) return true;
    if (left_remains < 0 || right_remains < 0) return false;
    return dfs(i + 1, left_remains - nums[i], right_remains) || dfs(i + 1, left_remains, right_remains - nums[i]);
  }

  vector<int> nums;

  bool canPartition(vector<int> &nums) {
    this->nums = nums;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    sort(nums.begin(), nums.end(), greater<int>());
    return dfs(0, sum / 2, sum / 2);
  }
};

#endif //CPP_0416__SOLUTION1_H_
