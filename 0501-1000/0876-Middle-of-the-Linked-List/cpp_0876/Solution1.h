//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0876__SOLUTION1_H_
#define CPP_0876__SOLUTION1_H_

#include "ListNode.h"

/**
 * 快慢指针
 */
class Solution {
 public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

#endif //CPP_0876__SOLUTION1_H_
