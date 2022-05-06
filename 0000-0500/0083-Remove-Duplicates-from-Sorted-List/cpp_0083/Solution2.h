//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0083__SOLUTION2_H_
#define CPP_0083__SOLUTION2_H_

#include "ListNode.h"

/**
 * recursion
 */
class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return nullptr;
    head->next = deleteDuplicates(head->next);
    return head->next && head->next->val == head->val ? head->next : head;
  }
};

#endif //CPP_0083__SOLUTION2_H_
