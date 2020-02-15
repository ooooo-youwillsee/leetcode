//
// Created by ooooo on 2020/2/15.
//
#ifndef CPP_0094__SOLUTION1_H_
#define CPP_0094__SOLUTION1_H_

#include "TreeNode.h"

/**
 * recursion
 */
class Solution {
 public:

  void dfs(TreeNode *node) {
    if (!node) return;
    dfs(node->left);
    ans.push_back(node->val);
    dfs(node->right);
  }
  vector<int> ans;

  vector<int> inorderTraversal(TreeNode *root) {
    dfs(root);
    return ans;
  }
};

#endif //CPP_0094__SOLUTION1_H_
