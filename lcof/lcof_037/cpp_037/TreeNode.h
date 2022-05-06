//
// Created by ooooo on 2020/3/23.
//
#ifndef CPP_037__TREENODE_H_
#define CPP_037__TREENODE_H_

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(vector<string> nums) {
    if (nums.empty()) return;
    this->val = stoi(nums[0]);
    this->left = this->right = nullptr;
    queue<TreeNode *> q;
    q.push(this);
    for (int i = 1, len = nums.size(); i < len; i += 2) {
      auto node = q.front();
      q.pop();
      if (nums[i] != "null") node->left = new TreeNode(stoi(nums[i]));
      if (i + 1 >= len) return;
      if (nums[i + 1] != "null") node->right = new TreeNode(stoi(nums[i + 1]));
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }
};

#endif //CPP_037__TREENODE_H_
