//
// Created by ooooo on 2020/3/22.
//
#ifndef CPP_035__SOLUTION2_H_
#define CPP_035__SOLUTION2_H_

#include "Node.h"
#include <unordered_map>

/**
 * dfs
 */
class Solution {
 public:

  Node *copy(Node *node) {
    if (!node) return nullptr;
    if (node_map.count(node)) return node_map[node];
    Node *new_node = new Node(node->val);
    node_map[node] = new_node;
    new_node->next = copy(node->next);
    new_node->random = copy(node->random);
    return new_node;
  }

  unordered_map<Node *, Node *> node_map;
  Node *copyRandomList(Node *head) {
    return copy(head);
  }
};
#endif //CPP_035__SOLUTION2_H_
