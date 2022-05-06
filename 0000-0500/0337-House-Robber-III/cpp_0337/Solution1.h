//
// Created by ooooo on 2020/2/25.
//
#ifndef CPP_0337__SOLUTION1_H_
#define CPP_0337__SOLUTION1_H_

#include "TreeNode.h"

using namespace std;

class Solution {
 public:

  int dfs(TreeNode *node, bool rob) {
    if (!node) return 0;
    // 添加下面这一行，减少递归次数，程序通过！！！
    if (!node->left && !node->right) return rob ? node->val : 0;
    int ans = 0;
    if (rob) {
      ans = node->val + dfs(node->left, false) + dfs(node->right, false);
    }
    return max(ans, dfs(node->left, true) + dfs(node->right, true));
  }

  int rob(TreeNode *root) {
    return dfs(root, true);
  }
};

#endif //CPP_0337__SOLUTION1_H_
