//
// Created by ooooo on 2020/3/17.
//
#ifndef CPP_026__TREENODE_H_
#define CPP_026__TREENODE_H_

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
    for (int i = 1, len = nums.size(); i < len;) {
      TreeNode *p = q.front();
      q.pop();
      if (nums[i] != INT_MAX) {
        p->left = new TreeNode(nums[i]);
      }
      if (i + 1 == len) return;
      if (nums[i + 1] != INT_MAX) {
        p->right = new TreeNode(nums[i + 1]);
      }
      i += 2;
      if (p->left) q.push(p->left);
      if (p->right) q.push(p->right);
    }
  }
};

#endif //CPP_026__TREENODE_H_
