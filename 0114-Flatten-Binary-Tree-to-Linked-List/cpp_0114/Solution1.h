//
// Created by ooooo on 2020/2/16.
//
#ifndef CPP_0114__SOLUTION1_H_
#define CPP_0114__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

  TreeNode *help(TreeNode *node) {
    if (!node) return nullptr;
    TreeNode *left = help(node->left);
    TreeNode *right = help(node->right);
    // 指针的引用置空
    node->left = nullptr;
    node->right = nullptr;
    if (!left && !right) {
      return node;
    } else if (!left) {
      node->right = right;
    } else if (!right) {
      node->right = left;
    } else {
      node->right = left;
      TreeNode *cur = node;
      while (cur->right) {
        cur = cur->right;
      }
      cur->right = right;
    }
    return node;
  }

  void flatten(TreeNode *root) {
    help(root);
  }
};

#endif //CPP_0114__SOLUTION1_H_
