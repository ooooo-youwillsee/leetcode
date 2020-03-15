//
// Created by ooooo on 2020/3/15.
//
#ifndef CPP_022__SOLUTION2_H_
#define CPP_022__SOLUTION2_H_

#include "ListNode.h"

class Solution {
 public:
  ListNode *getKthFromEnd(ListNode *head, int k) {
    ListNode *dummyHead = new ListNode(0), *cur = dummyHead;
    dummyHead->next = head;

    // 先前走 k-1 步
    for (int i = 0; i < k - 1; ++i) {
      if (cur) cur = cur->next;
      else return nullptr;
    }

    while (cur->next) {
      cur = cur->next;
      dummyHead = dummyHead->next;
    }
    return dummyHead;
  }
};

#endif //CPP_022__SOLUTION2_H_
