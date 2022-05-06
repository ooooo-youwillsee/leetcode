//
// Created by ooooo on 2020/4/11.
//
#ifndef CPP_055_1__SOLUTION2_H_
#define CPP_055_1__SOLUTION2_H_

#include "TreeNode.h"
#include <queue>

/**
 * dfs
 */
class Solution {
 public:

  void dfs(TreeNode *root, int level) {
    if (!root) {
      maxLevel = max(maxLevel, level);
      return;
    }
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }

  int maxLevel = 0;
  int maxDepth(TreeNode *root) {
    dfs(root, 0);
    return maxLevel;
  }
};

#endif //CPP_055_1__SOLUTION2_H_
