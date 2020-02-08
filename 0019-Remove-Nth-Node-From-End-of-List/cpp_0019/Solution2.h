//
// Created by ooooo on 2020/2/8.
//
#ifndef CPP_0019__SOLUTION2_H_
#define CPP_0019__SOLUTION2_H_

#include "ListNode.h"
#include <vector>

/**
 * 双指针， 其中一个先走n个，（如果有虚拟头指针，走n+1）
 */
class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummyNode = new ListNode(0), *cur = dummyNode, *prev = dummyNode;
    dummyNode->next = head;
    for (int i = 0; i < n + 1; ++i) {
      cur = cur->next;
    }
    while (cur) {
      cur = cur->next;
      prev = prev->next;
    }

    prev->next = prev->next->next;
    return dummyNode->next;
  }
};

#endif //CPP_0019__SOLUTION2_H_
