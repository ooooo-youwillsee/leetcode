//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_1290__SOLUTION2_H_
#define CPP_1290__SOLUTION2_H_

#include "ListNode.h"

/**
 * 二进制加法   i <<1 | xx
 */
class Solution {
 public:
  int getDecimalValue(ListNode *head) {
    int ans = 0;
    while (head) {
      ans = ans << 1 | head->val;
      head = head->next;
    }
    return ans;
  }
};

#endif //CPP_1290__SOLUTION2_H_
