//
// Created by ooooo on 2020/3/17.
//
#ifndef CPP_027__SOLUTION1_H_
#define CPP_027__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

  TreeNode *mirrorTree(TreeNode *root) {
    if (!root)return root;
    TreeNode *left = mirrorTree(root->left);
    TreeNode *right = mirrorTree(root->right);
    root->right = left;
    root->left = right;
    return root;
  }
};

#endif //CPP_027__SOLUTION1_H_
