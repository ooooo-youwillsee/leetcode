//
// Created by ooooo on 2020/3/13.
//
#ifndef CPP_018__SOLUTION2_H_
#define CPP_018__SOLUTION2_H_

#include "ListNode.h"

/**
 * 把后面的值逐一复制到 delNode 的 val
 */
class Solution {
 public:
  ListNode *deleteNode(ListNode *head, int val) {
    ListNode *dummyHead = new ListNode(0), *prev = dummyHead;
    dummyHead->next = head;
    while (prev->next) {
      if (prev->next->val == val) break;
      prev = prev->next;
    }

    ListNode *cur = prev->next;
    while (cur && cur->next) {
      ListNode *next = cur->next;
      cur->val = next->val;
      cur = cur->next;
      prev = prev->next;
    }
    prev->next = nullptr;

    return dummyHead->next;
  }
};

#endif //CPP_018__SOLUTION2_H_
