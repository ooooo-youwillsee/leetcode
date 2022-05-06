//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0160__SOLUTION1_H_
#define CPP_0160__SOLUTION1_H_

#include "ListNode.h"
#include <unordered_set>

/**
 * 哈希表
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> s;
    while (headA) {
      s.insert(headA);
      headA = headA->next;
    }
    while (headB) {
      if (s.count(headB)) return headB;
      headB = headB->next;
    }
    return nullptr;
  }
};

#endif //CPP_0160__SOLUTION1_H_
