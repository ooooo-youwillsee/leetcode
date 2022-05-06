//
// Created by ooooo on 2020/3/13.
//
#ifndef CPP_018__SOLUTION1_H_
#define CPP_018__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
  ListNode *deleteNode(ListNode *head, int val) {
    ListNode *dummyHead = new ListNode(0), *prev = dummyHead;
    dummyHead->next = head;
    while (prev->next) {
      if (prev->next->val == val) break;
      prev = prev->next;
    }
    if (prev) {
      ListNode *delNode = prev->next;
      prev->next = delNode->next;
    }
    return dummyHead->next;
  }
};

#endif //CPP_018__SOLUTION1_H_
