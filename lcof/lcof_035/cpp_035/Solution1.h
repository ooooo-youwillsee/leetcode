//
// Created by ooooo on 2020/3/22.
//
#ifndef CPP_035__SOLUTION1_H_
#define CPP_035__SOLUTION1_H_

#include "Node.h"
#include <unordered_map>

class Solution {
 public:

  Node *copyRandomList(Node *head) {
    if (!head) return nullptr;
    unordered_map<Node *, Node *> node_map;
    Node *dummyHead = new Node(0), *cur = dummyHead, *srcHead = head;
    while (head) {
      cur->next = new Node(head->val);
      node_map[head] = cur->next;
      cur = cur->next;
      head = head->next;
    }
    cur = dummyHead->next;
    while (srcHead) {
      if (srcHead->random) {
        cur->random = node_map[srcHead->random];
      }
      cur = cur->next;
      srcHead = srcHead->next;
    }
    return dummyHead->next;
  }
};

#endif //CPP_035__SOLUTION1_H_
