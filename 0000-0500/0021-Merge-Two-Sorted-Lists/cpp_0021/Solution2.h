//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0021__SOLUTION2_H_
#define CPP_0021__SOLUTION2_H_

#include "ListNode.h"

/**
 * 使用原先的节点 （效率高）
 */
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummyHead = new ListNode(0), *cur = dummyHead;
    while (l1 && l2) {
      if (l1->val == l2->val) {
        ListNode *temp1 = l1->next;
        ListNode *temp2 = l2->next;
        cur->next = l1;
        cur = cur->next;
        cur->next = l2;
        cur = cur->next;
        l1 = temp1;
        l2 = temp2;
      } else if (l1->val < l2->val) {
        ListNode *temp1 = l1->next;
        cur->next = l1;
        cur = cur->next;
        l1 = temp1;
      } else {
        ListNode *temp2 = l2->next;
        cur->next = l2;
        cur = cur->next;
        l2 = temp2;
      }
    }
    while (l1) {
      ListNode *temp1 = l1->next;
      cur->next = l1;
      cur = cur->next;
      l1 = temp1;
    }

    while (l2) {
      ListNode *temp2 = l2->next;
      cur->next = l2;
      cur = cur->next;
      l2 = temp2;
    }

    return dummyHead->next;
  }
};

#endif //CPP_0021__SOLUTION2_H_
