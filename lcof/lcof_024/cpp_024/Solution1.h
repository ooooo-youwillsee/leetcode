//
// Created by ooooo on 2020/3/16.
//
#ifndef CPP_024__SOLUTION1_H_
#define CPP_024__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:

  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head, *prev = nullptr;
    while (cur) {
      ListNode *node = cur;
      cur = node->next;
      node->next = prev;
      prev = node;
    }
    return prev;
  }
};

#endif //CPP_024__SOLUTION1_H_
