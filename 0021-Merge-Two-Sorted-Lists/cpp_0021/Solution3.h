//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0021__SOLUTION3_H_
#define CPP_0021__SOLUTION3_H_

#include "ListNode.h"

/**
 * recursion
 */
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};

#endif //CPP_0021__SOLUTION3_H_
