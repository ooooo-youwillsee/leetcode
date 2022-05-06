//
// Created by ooooo on 2020/3/16.
//
#ifndef CPP_025__SOLUTION1_H_
#define CPP_025__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *dummyHead = new ListNode(0), *cur = dummyHead;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1) {
      cur->next = l1;
    }
    if (l2) {
      cur->next = l2;
    }
    return dummyHead->next;
  }
};

#endif //CPP_025__SOLUTION1_H_
