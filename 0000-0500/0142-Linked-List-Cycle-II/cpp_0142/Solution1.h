//
// Created by ooooo on 2020/2/17.
//
#ifndef CPP_0142__SOLUTION1_H_
#define CPP_0142__SOLUTION1_H_

#include "LIstNode.h"
#include <unordered_set>

/**
 * 哈希
 */
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> set;
    while(head) {
      if (set.count(head)) {
        return head;
      }
      set.insert(head);
      head = head->next;
    }
    return nullptr;
  }
};

#endif //CPP_0142__SOLUTION1_H_
