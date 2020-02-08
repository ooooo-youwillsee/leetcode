//
// Created by ooooo on 2020/2/8.
//
#ifndef CPP_0019__SOLUTION1_H_
#define CPP_0019__SOLUTION1_H_

#include "ListNode.h"
#include <vector>

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    vector<ListNode *> nodes;
    ListNode *dummyNode = new ListNode(0), *cur = dummyNode;
    dummyNode->next = head;
    while (cur) {
      nodes.push_back(cur);
      cur = cur->next;
    }
    // 删除最后一个，应该指向NULL
    nodes.push_back(nullptr);
    nodes[nodes.size() - n - 1]->next = nodes[nodes.size() - n + 1];
    return nodes[0]->next;
  }
};

#endif //CPP_0019__SOLUTION1_H_
