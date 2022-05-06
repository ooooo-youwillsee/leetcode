//
// Created by ooooo on 2020/2/16.
//
#ifndef CPP_0114__SOLUTION3_H_
#define CPP_0114__SOLUTION3_H_

#include "TreeNode.h"
/**
 * in-place
 */
class Solution {
 public:

  void flatten(TreeNode *root) {
    while (root) {
      if (!root->left) {
        root = root->right;
      } else {
        TreeNode *prev = root->left;
        while (prev->right) prev = prev->right;
        prev->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        root = root->right;
      }
    }
  }
};

#endif //CPP_0114__SOLUTION3_H_
