//
// Created by ooooo on 2020/4/11.
//
#ifndef CPP_055_2__SOLUTION1_H_
#define CPP_055_2__SOLUTION1_H_

#include "TreeNode.h"
#include <math.h>
#include <unordered_map>

class Solution {
 public:

  int getHeight(TreeNode *node) {
    if (map.find(node) != map.end()) return map[node];
    if (!node) return 0;
    return map[node] = max(getHeight(node->left), getHeight(node->right)) + 1;
  }
  unordered_map<TreeNode *, int> map;

  bool isBalanced(TreeNode *root) {
    if (!root) return true;
    if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }
};

#endif //CPP_055_2__SOLUTION1_H_
