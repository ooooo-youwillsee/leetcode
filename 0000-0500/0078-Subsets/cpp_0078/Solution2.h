//
// Created by ooooo on 2020/2/14.
//
#ifndef CPP_0078__SOLUTION2_H_
#define CPP_0078__SOLUTION2_H_
#include <iostream>
#include <vector>

using namespace std;

/**
 * 回溯
 */
class Solution {
 public:

  void dfs(int i) {
    ans.push_back(num);
    for (; i < nums.size(); ++i) {
      num.push_back(nums[i]);
      dfs(i + 1);
      num.pop_back();
    }
  }

  vector<vector<int>> ans;
  vector<int> nums, num;

  vector<vector<int>> subsets(vector<int> &nums) {
    this->nums = nums;
    dfs(0);
    return ans;
  }
};

#endif //CPP_0078__SOLUTION2_H_
