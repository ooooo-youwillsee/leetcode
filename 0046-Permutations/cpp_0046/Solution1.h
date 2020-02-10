//
// Created by ooooo on 2020/2/10.
//
#ifndef CPP_0046__SOLUTION1_H_
#define CPP_0046__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

  void dfs() {
    if (marked.size() == nums.size()) {
      ans.push_back(added);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (marked.count(nums[i])) continue;
      marked.insert(nums[i]);
      added.push_back(nums[i]);
      dfs();
      marked.erase(nums[i]);
      added.pop_back();
    }
  }

  vector<int> nums;
  vector<vector<int>> ans;
  unordered_set<int> marked;
  vector<int> added;

  vector<vector<int>> permute(vector<int> &nums) {
    this->nums = nums;
    dfs();
    return ans;
  }
};

#endif //CPP_0046__SOLUTION1_H_
