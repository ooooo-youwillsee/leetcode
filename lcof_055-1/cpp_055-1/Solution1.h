//
// Created by ooooo on 2020/4/11.
//
#ifndef CPP_055_1__SOLUTION1_H_
#define CPP_055_1__SOLUTION1_H_

#include "TreeNode.h"
#include <queue>

/**
 * bfs
 */
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      level++;
      for (int i = 0, len = q.size(); i < len; ++i) {
        auto node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return level;
  }
};

#endif //CPP_055_1__SOLUTION1_H_
