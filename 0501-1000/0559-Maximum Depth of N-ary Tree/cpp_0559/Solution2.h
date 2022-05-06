//
// Created by ooooo on 2019/12/29.
//
#ifndef CPP_0599_SOLUTION2_H
#define CPP_0599_SOLUTION2_H

#include "Node.h"

class Solution {

 public:
  int maxDepth(Node *root) {
    if (!root) return 0;
    int max = 0;
    for (int i = 0; i < root->children.size(); ++i) {
      int depth = maxDepth(root->children[i]);
      max = std::max(max, depth);
    }
    return max + 1;
  }
};

#endif //CPP_0599_SOLUTION2_H
