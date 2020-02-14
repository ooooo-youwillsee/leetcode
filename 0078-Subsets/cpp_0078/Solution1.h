//
// Created by ooooo on 2020/2/14.
//
#ifndef CPP_0078__SOLUTION1_H_
#define CPP_0078__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 回溯
 */
class Solution {
 public:

  void dfs(int cur_count, int count, int index) {
    if (cur_count == count) {
      ans.push_back(num);
      return;
    }
    for (int i = index; i < nums.size(); ++i) {
      num.push_back(nums[i]);
      dfs(cur_count + 1, count, i + 1);
      num.pop_back();
    }
  }

  vector<vector<int>> ans;
  vector<int> nums, num;

  vector<vector<int>> subsets(vector<int> &nums) {
    this->nums = nums;
    for (int i = 0; i <= nums.size(); ++i) {
      num.clear();
      dfs(0, i, 0);
    }
    return ans;
  }
};

#endif //CPP_0078__SOLUTION1_H_
