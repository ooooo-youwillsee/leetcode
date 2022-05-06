//
// Created by ooooo on 2020/3/20.
//
#ifndef CPP_032_2__SOLUTION2_H_
#define CPP_032_2__SOLUTION2_H_

#include "TreeNode.h"
#include <queue>

/**
 * dfs
 */
class Solution {
 public:

  void dfs(TreeNode *node, int level) {
    if (!node) return;
    if (ans.size() <= level) {
      ans.push_back({});
    }
    ans[level].emplace_back(node->val);
    dfs(node->left, level + 1);
    dfs(node->right, level + 1);
  }

  vector<vector<int>> ans;

  vector<vector<int>> levelOrder(TreeNode *root) {
    dfs(root, 0);
    return ans;
  }
};

#endif //CPP_032_2__SOLUTION2_H_
