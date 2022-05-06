//
// Created by ooooo on 2020/3/18.
//
#ifndef CPP_028__SOLUTION1_H_
#define CPP_028__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

  bool dfs(TreeNode *node1, TreeNode *node2) {
    if (!node1 && !node2) return true;
    if (!node1 || !node2) return false;
    return node1->val == node2->val == dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
  }

  bool isSymmetric(TreeNode *root) {
    return dfs(root, root);
  }
};

#endif //CPP_028__SOLUTION1_H_
