//
// Created by ooooo on 2020/3/19.
//
#ifndef CPP_030__SOLUTION1_H_
#define CPP_030__SOLUTION1_H_

#include <iostream>

using namespace std;

class MinStack {

 private:
  struct Node {
    Node *next;
    int val;
    Node(Node *next, int val) : next(next), val(val) {}
    Node(int val) : val(val), next(nullptr) {}
  };

  Node *dummyHead;
  int size;

 public:
  /** initialize your data structure here. */
  MinStack() {
    dummyHead = new Node(0);
    size = 0;
  }

  void push(int x) {
    dummyHead->next = new Node(dummyHead->next, x);
    size += 1;
  }

  void pop() {
    if (size == 0) return;
    dummyHead->next = dummyHead->next->next;
    size--;
  }

  int top() {
    if (size == 0) return -1;
    return dummyHead->next->val;
  }

  int min() {
    Node *cur = dummyHead->next;
    int min_value = INT_MAX;
    while (cur) {
      min_value = std::min(min_value, cur->val);
      cur = cur->next;
    }
    return min_value;
  }
};

#endif //CPP_030__SOLUTION1_H_
