//
// Created by ooooo on 2020/2/16.
//
#ifndef CPP_0114__SOLUTION2_H_
#define CPP_0114__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:

  TreeNode *prev = nullptr;
  void flatten(TreeNode *root) {
    if (!root) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = nullptr;
    prev = root;
  }
};

#endif //CPP_0114__SOLUTION2_H_
