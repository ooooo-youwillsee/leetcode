//
// Created by ooooo on 2020/2/18.
//
#ifndef CPP_0148__SOLUTION1_H_
#define CPP_0148__SOLUTION1_H_

#include "ListNode.h"

/**
 * 复杂度要求 O(nlogn) ==> 归并排序
 * recursion
 */
class Solution {
 public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *low = head, *fast = head->next;
    while (fast && fast->next) {
      low = low->next;
      fast = fast->next->next;
    }
    ListNode *mid = low->next;
    low->next = nullptr;
    ListNode *left = sortList(head), *right = sortList(mid);
    ListNode  *dummyHead = new ListNode(-1), *cur = dummyHead;
    while (left && right) {
      if (left->val <= right->val) {
        cur->next = left;
        left = left->next;
      } else {
        cur->next = right;
        right = right->next;
      }
      cur = cur->next;
    }
    cur->next = left ? left : right;
    return dummyHead->next;
  }

};

#endif //CPP_0148__SOLUTION1_H_
