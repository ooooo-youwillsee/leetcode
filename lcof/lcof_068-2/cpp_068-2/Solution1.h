//
// Created by ooooo on 2020/4/26.
//
#ifndef CPP_068_2__SOLUTION1_H_
#define CPP_068_2__SOLUTION1_H_

#include "TreeNode.h"
#include <vector>

class Solution {
 public:

  bool dfs(TreeNode *node, TreeNode *p, vector<TreeNode *> &pNodes) {
    if (!node) return false;
    if (node->val == p->val || dfs(node->left, p, pNodes)
        || dfs(node->right, p, pNodes)) {
      pNodes.push_back(node);
      return true;
    }
    return false;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return nullptr;
    if (p == q) return p;
    vector<TreeNode *> pNodes, qNodes;
    dfs(root, p, pNodes);
    dfs(root, q, qNodes);
    for (int i = pNodes.size() - 1, j = qNodes.size() - 1; i >= 0 && j >= 0; --i, --j) {
      if (pNodes[i] != qNodes[j]) return pNodes[i + 1];
    }
    return pNodes.size() < qNodes.size() ? pNodes[0] : qNodes[0];
  }
};

#endif //CPP_068_2__SOLUTION1_H_
