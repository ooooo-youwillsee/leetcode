//
// Created by ooooo on 2020/3/13.
//
#ifndef CPP_018__SOLUTION3_H_
#define CPP_018__SOLUTION3_H_

#include "ListNode.h"

/**
 * recursion
 */
class Solution {
 public:
  ListNode *deleteNode(ListNode *head, int val) {
    if (!head) return nullptr;
    if (head->val == val) return head->next;
    head->next = deleteNode(head->next, val);
    return head;
  }
};

#endif //CPP_018__SOLUTION3_H_
