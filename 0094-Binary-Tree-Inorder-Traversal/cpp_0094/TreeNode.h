//
// Created by ooooo on 2020/2/15.
//
#ifndef CPP_0094__TREENODE_H_
#define CPP_0094__TREENODE_H_

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(vector<int> nums) {
    if (nums.empty()) return;
    this->val = nums[0];
    this->left = this->right = nullptr;
    queue<TreeNode *> q;
    q.push(this);
    for (int i = 1; i < nums.size() && !q.empty();) {
      TreeNode *node = q.front();
      q.pop();
      if (nums[i] == INT_MAX) {
        node->left = nullptr;
      } else {
        node->left = new TreeNode(nums[i]);
        q.push(node->left);
      }
      if (i + 1 >= nums.size()) return;
      if (nums[i + 1] == INT_MAX) {
        node->right = nullptr;
      } else {
        node->right = new TreeNode(nums[i + 1]);
        q.push(node->right);
      }
      i += 2;
    }
  }
};

#endif //CPP_0094__TREENODE_H_
