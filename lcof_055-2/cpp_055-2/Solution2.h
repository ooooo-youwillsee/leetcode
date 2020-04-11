//
// Created by ooooo on 2020/4/11.
//
#ifndef CPP_055_2__SOLUTION2_H_
#define CPP_055_2__SOLUTION2_H_

#include "TreeNode.h"
#include <math.h>
#include <unordered_map>

/**
 * 后序遍历
 */
class Solution {
 public:

  bool isBalanced(TreeNode *node, int &depth) {
    if (!node) {
      depth = 0;
      return true;
    }
    int left = 0, right = 0;
    if (isBalanced(node->left, left) && isBalanced(node->right, right)) {
      if (abs(left - right) <= 1) {
        depth = max(left, right) + 1;
        return true;
      }
    }
    return false;
  }

  bool isBalanced(TreeNode *root) {
    if (!root) return true;
    int depth = 0;
    return isBalanced(root, depth);
  }
};

#endif //CPP_055_2__SOLUTION2_H_
