//
// Created by ooooo on 2020/3/7.
//
#ifndef CPP_007__SOLUTION1_H_
#define CPP_007__SOLUTION1_H_

#include "TreeNode.h"
#include <unordered_map>

class Solution {
 public:

  TreeNode *dfs(TreeNode *node, int l, int r) {
    if (l > r) return nullptr;
    int root_value = preorder[i++];
    int root_index = in_map[root_value];
    node = new TreeNode(root_value);
    node->left = dfs(node->left, l, root_index - 1);
    node->right = dfs(node->right, root_index + 1, r);
    return node;
  }

  vector<int> preorder;
  unordered_map<int, int> in_map;
  int i = 0;

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0, len = inorder.size(); i < len; ++i) {
      in_map[inorder[i]] = i;
    }
    this->preorder = preorder;
    return dfs(nullptr, 0, inorder.size() - 1);
  }
};
#endif //CPP_007__SOLUTION1_H_
