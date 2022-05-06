//
// Created by ooooo on 2020/3/21.
//
#ifndef CPP_032_3__SOLUTION2_H_
#define CPP_032_3__SOLUTION2_H_

#include "TreeNode.h"
#include <queue>

/**
 * dfs
 */
class Solution {
 public:

  void dfs(TreeNode *root, int level) {
    if (!root) return;
    if (ans.size() <= level) {
      ans.push_back({});
    }
    ans[level].emplace_back(root->val);
    level += 1;
    dfs(root->left, level);
    dfs(root->right, level);
  }

  vector<vector<int>> ans;
  vector<vector<int>> levelOrder(TreeNode *root) {
    dfs(root, 0);
    for (int i = 0, len = ans.size(); i < len; ++i) {
      if ((i & 1) == 1) reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
  }
};
#endif //CPP_032_3__SOLUTION2_H_
