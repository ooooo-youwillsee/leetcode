//
// Created by ooooo on 2020/3/7.
//
#ifndef CPP_006__SOLUTION3_H_
#define CPP_006__SOLUTION3_H_

#include "ListNode.h"

/**
 * O(n)
 */
class Solution {
 public:

  void dfs(ListNode *node) {
    if (!node) return;
    dfs(node->next);
    ans.emplace_back(node->val);
  }

  vector<int> ans;
  vector<int> reversePrint(ListNode *head) {
    dfs(head);
    return ans;
  }
};

#endif //CPP_006__SOLUTION3_H_
