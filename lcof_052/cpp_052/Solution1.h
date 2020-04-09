//
// Created by ooooo on 2020/4/9.
//
#ifndef CPP_052__SOLUTION1_H_
#define CPP_052__SOLUTION1_H_

#include "ListNode.h"
#include <unordered_set>

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> nodes;
    for (; headA; headA = headA->next) nodes.insert(headA);
    for (; headB; headB = headB->next) {
      if (nodes.count(headB)) return headB;
    }
    return nullptr;
  }
};

#endif //CPP_052__SOLUTION1_H_
