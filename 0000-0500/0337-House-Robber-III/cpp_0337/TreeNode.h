//
// Created by ooooo on 2020/2/25.
//
#ifndef CPP_0337__TREENODE_H_
#define CPP_0337__TREENODE_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}

  TreeNode(vector<int> nums) : TreeNode(nums[0]) {
    queue<TreeNode *> q;
    q.push(this);
    for (int i = 1; i < nums.size(); i += 2) {
      auto node = q.front();
      q.pop();
      if (nums[i] != INT_MAX) {
        node->left = new TreeNode(nums[i]);
      }
      if (i + 1 >= nums.size()) return;
      if (nums[i + 1] != INT_MAX) {
        node->right = new TreeNode(nums[i + 1]);
      }
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }

};

#endif //CPP_0337__TREENODE_H_
