//
// Created by ooooo on 2020/2/17.
//
#ifndef CPP_0142__SOLUTION2_H_
#define CPP_0142__SOLUTION2_H_

#include "LIstNode.h"

/**
 * 快慢指针
 */
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *low = head, *fast = head;
    bool hasCycle = false;
    while (fast && fast->next) {
      low = low->next;
      fast = fast->next->next;
      if (low == fast) {
        hasCycle = true;
        break;
      }
    }
    if (!hasCycle) return nullptr;
    low = head;
    while (low != fast) {
      low = low->next;
      fast = fast->next;
    }
    return low;
  }
};

#endif //CPP_0142__SOLUTION2_H_
