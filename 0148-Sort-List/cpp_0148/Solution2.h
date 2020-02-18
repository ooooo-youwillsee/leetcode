//
// Created by ooooo on 2020/2/18.
//
#ifndef CPP_0148__SOLUTION2_H_
#define CPP_0148__SOLUTION2_H_

#include "ListNode.h"

/**
 * 复杂度要求 O(nlogn) ==> 归并排序
 * 自底向上
 */
class Solution {
 public:
  ListNode *sortList(ListNode *head) {
    ListNode *cur = head;
    int size = 0;
    while (cur) {
      cur = cur->next;
      size++;
    }
    ListNode *res = new ListNode(0);
    res->next = head;
    for (int i = 1; i < size; i *= 2) {
      ListNode *prev = res, *h = res->next;
      int j = 0;
      while (h) {
        ListNode *h1 = h;
        j = i;
        while (j && h) {
          h = h->next;
          j--;
        }
        // 如果 j 不为 0，说明没有后面的元素，不用比较
        if (j) break;

        ListNode *h2 = h;
        j = i;
        while (j && h) {
          h = h->next;
          j--;
        }

        int c1 = i, c2 = i - j;
        while (c1 && c2) {
          if (h1->val <= h2->val) {
            prev->next = h1;
            h1 = h1->next;
            c1--;
          } else {
            prev->next = h2;
            h2 = h2->next;
            c2--;
          }
          prev = prev->next;
        }
        prev->next = c1 ? h1 : h2;
        while (c1 > 0 || c2 > 0) {
          prev = prev->next;
          c1--;
          c2--;
        }
        prev->next = h;
      }
    }
    return res->next;
  }

};

#endif //CPP_0148__SOLUTION2_H_
