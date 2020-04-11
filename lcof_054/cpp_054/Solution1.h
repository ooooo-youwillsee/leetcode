//
// Created by ooooo on 2020/4/11.
//
#ifndef CPP_054__SOLUTION1_H_
#define CPP_054__SOLUTION1_H_

#include "TreeNode.h"
#include <vector>

class Solution {
 public:

  void dfs(TreeNode *node) {
    if (!node) return;
    dfs(node->left);
    nums.push_back(node->val);
    dfs(node->right);
  }

  vector<int> nums;

  int kthLargest(TreeNode *root, int k) {
    dfs(root);
    return nums[nums.size() - k];
  }
};

#endif //CPP_054__SOLUTION1_H_
