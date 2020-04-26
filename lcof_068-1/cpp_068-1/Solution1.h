//
// Created by ooooo on 2020/4/26.
//
#ifndef CPP_068_1__SOLUTION1_H_
#define CPP_068_1__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return nullptr;
    if (root->val < p->val && root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    } else if (root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
  }
};

#endif //CPP_068_1__SOLUTION1_H_
