//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0160__SOLUTION2_H_
#define CPP_0160__SOLUTION2_H_

#include "ListNode.h"
#include <unordered_set>

/**
 * 双指针 (循环走A-B)
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
      pA = pA ? pA->next : headB;
      pB = pB ? pB->next : headA;
    }
    return pA;
  }
};

#endif //CPP_0160__SOLUTION2_H_
