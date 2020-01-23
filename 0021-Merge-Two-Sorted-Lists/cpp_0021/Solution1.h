//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0021__SOLUTION1_H_
#define CPP_0021__SOLUTION1_H_

#include "ListNode.h"

/**
 * 每个节点重新new
 */
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummyHead = new ListNode(0), *cur = dummyHead;
    while (l1 && l2) {
      if (l1->val == l2->val) {
        cur->next = new ListNode(l1->val);
        cur = cur->next;
        cur->next = new ListNode(l2->val);
        cur = cur->next;
        l1 = l1->next;
        l2 = l2->next;
      } else if (l1->val < l2->val) {
        cur->next = new ListNode(l1->val);
        cur = cur->next;
        l1 = l1->next;
      } else {
        cur->next = new ListNode(l2->val);
        cur = cur->next;
        l2 = l2->next;
      }
    }
    while (l1) {
      cur->next = new ListNode(l1->val);
      cur = cur->next;
      l1 = l1->next;
    }

    while (l2) {
      cur->next = new ListNode(l2->val);
      cur = cur->next;
      l2 = l2->next;
    }

    return dummyHead->next;
  }
};

#endif //CPP_0021__SOLUTION1_H_
