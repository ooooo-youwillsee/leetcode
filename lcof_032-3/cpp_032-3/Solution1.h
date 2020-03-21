//
// Created by ooooo on 2020/3/21.
//
#ifndef CPP_032_3__SOLUTION1_H_
#define CPP_032_3__SOLUTION1_H_

#include "TreeNode.h"
#include <queue>

/**
 * bfs
 */
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
      vector<int> row;
      for (int i = 0, len = q.size(); i < len; ++i) {
        auto node = q.front();
        q.pop();
        row.emplace_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      if (flag) reverse(row.begin(), row.end());
      flag = !flag;
      ans.push_back(row);
    }
    return ans;
  }
};

#endif //CPP_032_3__SOLUTION1_H_
