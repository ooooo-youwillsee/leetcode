//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_1290__SOLUTION1_H_
#define CPP_1290__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
  int getDecimalValue(ListNode *head) {
    string s = "";
    while (head) {
      s += to_string(head->val);
      head = head->next;
    }
    return stoi(s, 0, 2);
  }
};

#endif //CPP_1290__SOLUTION1_H_
