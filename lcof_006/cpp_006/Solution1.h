//
// Created by ooooo on 2020/3/7.
//
#ifndef CPP_006__SOLUTION1_H_
#define CPP_006__SOLUTION1_H_

#include "ListNode.h"


/**
 * O(n^2)
 */
class Solution {
 public:
  vector<int> reversePrint(ListNode *head) {
    ListNode *cur = head;
    vector<int> ans;
    while (cur) {
      ans.insert(ans.begin(), cur->val);
      cur = cur->next;
    }
    return ans;
  }
};

#endif //CPP_006__SOLUTION1_H_
