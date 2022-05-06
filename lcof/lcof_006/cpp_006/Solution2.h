//
// Created by ooooo on 2020/3/7.
//
#ifndef CPP_006__SOLUTION2_H_
#define CPP_006__SOLUTION2_H_


#include "ListNode.h"


/**
 * O(n)
 */
class Solution {
 public:
  vector<int> reversePrint(ListNode *head) {
    ListNode *cur = head;
    vector<int> ans;
    while (cur) {
      ans.emplace_back(cur->val);
      cur = cur->next;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};


#endif //CPP_006__SOLUTION2_H_
