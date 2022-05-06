//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0876__SOLUTION2_H_
#define CPP_0876__SOLUTION2_H_

#include "ListNode.h"
#include <vector>

/**
 * 遍历数组存放
 */
class Solution {
 public:
  ListNode *middleNode(ListNode *head) {
    vector<ListNode *> ans;
    while (head) {
      ans.push_back(head);
      head = head->next;
    }
    int size = ans.size();
    return size % 2 == 0 ? ans[size / 2 + 1] : ans[size / 2];
  }
};

#endif //CPP_0876__SOLUTION2_H_
