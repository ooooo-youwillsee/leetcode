//
// Created by ooooo on 2020/2/16.
//
#ifndef CPP_0105__SOLUTION1_H_
#define CPP_0105__SOLUTION1_H_

#include "TreeNode.h"
#include <vector>
#include <unordered_map>

class Solution {
 public:

  TreeNode *help(int in_l, int in_r) {
    if (in_l > in_r) return nullptr;
    int root_value = preorder[preIndex++];
    TreeNode *root = new TreeNode(root_value);
    int index = inorder_map[root_value];
    root->left = help(in_l, index - 1);
    root->right = help(index + 1, in_r);
    return root;
  }

  int preIndex = 0;
  vector<int> preorder;
  unordered_map<int, int> inorder_map;

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) return nullptr;
    this->preorder = preorder;
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
      inorder_map[inorder[i]] = i;
    }
    return help(0, n - 1);
  }
};

#endif //CPP_0105__SOLUTION1_H_
