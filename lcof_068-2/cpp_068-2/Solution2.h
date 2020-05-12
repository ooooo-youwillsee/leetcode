//
// Created by ooooo on 2020/4/26.
//
#ifndef CPP_068_2__SOLUTION2_H_
#define CPP_068_2__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return nullptr;
    if (root == q || root == p) return root;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    if (left) return left;
    if (right) return right;
    return nullptr;
  }
};

#endif //CPP_068_2__SOLUTION2_H_
