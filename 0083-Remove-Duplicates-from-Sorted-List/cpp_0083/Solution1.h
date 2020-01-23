//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0083__SOLUTION1_H_
#define CPP_0083__SOLUTION1_H_

#include "ListNode.h"

/**
 * loop
 */
class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur && cur->next) {
      if (cur->val == cur->next->val) {
        ListNode *delNode = cur->next;
        cur->next = delNode->next;
        delNode->next = nullptr;
        delete delNode;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};

#endif //CPP_0083__SOLUTION1_H_
