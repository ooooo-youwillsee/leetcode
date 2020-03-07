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
    ans.emplace_back(node->val);
    dfs(node->next);
  }

  vector<int> ans;
  vector<int> reversePrint(ListNode *head) {
    dfs(head);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

#endif //CPP_006__SOLUTION3_H_
