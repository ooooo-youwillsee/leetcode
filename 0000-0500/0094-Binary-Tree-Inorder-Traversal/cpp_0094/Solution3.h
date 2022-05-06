//
// Created by ooooo on 2020/2/15.
//
#ifndef CPP_0094__SOLUTION3_H_
#define CPP_0094__SOLUTION3_H_

#include "TreeNode.h"
#include <stack>

/**
 * iteration
 */
class Solution {
 public:

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> stack;
    TreeNode *curNode = root;
    while (curNode != nullptr || !stack.empty()) {
      while (curNode) {
        stack.push(curNode);
        curNode = curNode->left;
      }
      curNode = stack.top();
      stack.pop();
      ans.push_back(curNode->val);
      curNode = curNode->right;
    }
    return ans;
  }
};

#endif //CPP_0094__SOLUTION3_H_
