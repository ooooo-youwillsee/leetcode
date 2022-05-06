//
// Created by ooooo on 2020/2/10.
//
#ifndef CPP_0039__SOLUTION1_H_
#define CPP_0039__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

/**
 * vector#push_back() 会复制数据
 *
 * 允许重复数字 --> i可以再次取到，利用排序保证结果不重复
 */
class Solution {
 public:

  void help(vector<int> nums, vector<int> &candidates, int start, int target) {
    if (target == 0) {
      ans.push_back(nums);
      return;
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
      auto num = candidates[i];
      nums.push_back(num);
      help(nums, candidates, i, target - num);
      nums.pop_back();
    }
  }

  vector<vector<int>> ans;

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    help(vector<int>(), candidates, 0, target);
    return ans;
  }
};

#endif //CPP_0039__SOLUTION1_H_
