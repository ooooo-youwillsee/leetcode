//
// Created by ooooo on 2020/3/22.
//
#ifndef CPP_034__SOLUTION1_H_
#define CPP_034__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

  void dfs(TreeNode *node, int sum, vector<int> &nums) {
    if (!node) return;
    sum -= node->val;
    nums.push_back(node->val);
    if (sum == 0 && !node->left && !node->right) ans.push_back(nums);
    dfs(node->left, sum, nums);
    dfs(node->right, sum, nums);
    nums.pop_back();
  }

  vector<vector<int>> ans;

  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<int> nums;
    dfs(root, sum, nums);
    return ans;
  }
};

#endif //CPP_034__SOLUTION1_H_
