//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0237__SOLUTION1_H_
#define CPP_0237__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
  void deleteNode(ListNode *node) {
    ListNode *cur = node;
    while (cur && cur->next) {
      cur->val = cur->next->val;
      if (!cur->next->next) {
        cur->next = nullptr;
        break;
      }
      cur = cur->next;
    }
  }
};

#endif //CPP_0237__SOLUTION1_H_
