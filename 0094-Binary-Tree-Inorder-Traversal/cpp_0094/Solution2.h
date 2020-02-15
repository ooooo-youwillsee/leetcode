//
// Created by ooooo on 2020/2/15.
//
#ifndef CPP_0094__SOLUTION2_H_
#define CPP_0094__SOLUTION2_H_

#include "TreeNode.h"
#include <stack>
#include <unordered_set>

/**
 * iteration
 */
class Solution {
 public:

  vector<int> inorderTraversal(TreeNode *root) {
    if (!root) return {};
    vector<int> ans;
    stack<TreeNode *> stack;
    unordered_set<TreeNode *> set;
    stack.push(root);
    TreeNode *curNode;
    while (!stack.empty()) {
      curNode = stack.top();
      while (!set.count(curNode) && curNode->left) {
        set.insert(curNode);
        stack.push(curNode->left);
        curNode = curNode->left;
      }
      curNode = stack.top();
      stack.pop();
      ans.push_back(curNode->val);
      if (curNode->right) {
        stack.push(curNode->right);
      }
    }
    return ans;
  }
};

#endif //CPP_0094__SOLUTION2_H_
