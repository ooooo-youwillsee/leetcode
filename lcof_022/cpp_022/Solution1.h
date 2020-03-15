//
// Created by ooooo on 2020/3/15.
//
#ifndef CPP_022__SOLUTION1_H_
#define CPP_022__SOLUTION1_H_

#include "ListNode.h"
#include <vector>

class Solution {
 public:
  ListNode *getKthFromEnd(ListNode *head, int k) {
    if (!head) return nullptr;
    vector<ListNode *> vec;
    while (head) {
      vec.push_back(head);
      head = head->next;
    }
    if (k > vec.size()) return nullptr;
    return vec[vec.size() - k];
  }
};

#endif //CPP_022__SOLUTION1_H_
