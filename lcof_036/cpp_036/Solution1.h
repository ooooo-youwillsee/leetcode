//
// Created by ooooo on 2020/3/23.
//
#ifndef CPP_036__SOLUTION1_H_
#define CPP_036__SOLUTION1_H_

#include "Node.h"

class Solution {
 public:

  void dfs(Node *node) {
    if (!node) return;
    dfs(node->left);
    if (!head) {
      head = node;
      prev = node;
    } else {
      prev->right = node;
      node->left = prev;
      prev = node;
    }
    dfs(node->right);
  }
  Node *head, *prev;
  Node *treeToDoublyList(Node *root) {
    if (!root) return nullptr;
    dfs(root);
    head->left = prev;
    prev->right = head;
    return head;
  }
};

#endif //CPP_036__SOLUTION1_H_
