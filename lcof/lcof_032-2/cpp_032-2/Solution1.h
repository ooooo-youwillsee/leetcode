//
// Created by ooooo on 2020/3/20.
//
#ifndef CPP_032_2__SOLUTION1_H_
#define CPP_032_2__SOLUTION1_H_

#include "TreeNode.h"
#include <queue>

/**
 * level order
 */
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if(!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> level;
      for (int i = 0,len = q.size(); i < len; ++i) {
        auto node = q.front();
        q.pop();
        level.emplace_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      ans.emplace_back(level);
    }
    return ans;
  }
};

#endif //CPP_032_2__SOLUTION1_H_
