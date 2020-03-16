//
// Created by ooooo on 2020/3/16.
//
#ifndef CPP_025__SOLUTION2_H_
#define CPP_025__SOLUTION2_H_

#include "ListNode.h"

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode * ans = nullptr;
    if (l1->val <= l2->val) {
      ans = l1;
      ans->next = mergeTwoLists(l1->next, l2);
    }else {
      ans = l2;
      ans->next = mergeTwoLists(l1, l2->next);
    }
    return ans;
  }
};

#endif //CPP_025__SOLUTION2_H_
