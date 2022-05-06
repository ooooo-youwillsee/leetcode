//
// Created by ooooo on 2020/4/9.
//
#ifndef CPP_052__SOLUTION2_H_
#define CPP_052__SOLUTION2_H_

#include "ListNode.h"

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA = headA, *nodeB = headB;
    while (nodeA && nodeB) {
      nodeA = nodeA->next;
      nodeB = nodeB->next;
    }

    if (!nodeA) {
      nodeA = headB;
    }
    if (!nodeB) {
      nodeB = headA;
    }

    while (nodeA && nodeB) {
      nodeA = nodeA->next;
      nodeB = nodeB->next;
    }

    if (!nodeA) {
      nodeA = headB;
    }
    if (!nodeB) {
      nodeB = headA;
    }

    while (nodeA && nodeB) {
      if (nodeA == nodeB) return nodeA;
      nodeA = nodeA->next;
      nodeB = nodeB->next;
    }

    return nullptr;
  }
};
#endif //CPP_052__SOLUTION2_H_
