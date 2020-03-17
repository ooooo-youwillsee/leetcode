//
// Created by ooooo on 2020/3/17.
//
#ifndef CPP_026__SOLUTION1_H_
#define CPP_026__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

  bool isSameTree(TreeNode *node1, TreeNode *node2) {
    if (!node2) return true;
    if (!node1) return false;
    return node1->val == node2->val && isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
  }

  bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (!A || !B) return false;
    if (A->val != B->val) {
      return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    } else {
      return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
  }
};

#endif //CPP_026__SOLUTION1_H_
