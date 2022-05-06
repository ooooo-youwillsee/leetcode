//
// Created by ooooo on 2020/4/11.
//
#ifndef CPP_055_1__SOLUTION3_H_
#define CPP_055_1__SOLUTION3_H_

#include "TreeNode.h"
#include <queue>

/**
 * dfs
 */
class Solution {
 public:

  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

#endif //CPP_055_1__SOLUTION3_H_
