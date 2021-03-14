//
// Created by ooooo on 2020/1/13.
//
#ifndef CPP_0705__SOLUTION1_H_
#define CPP_0705__SOLUTION1_H_

#include <iostream>

using namespace std;

class MyHashSet {

 private:

  struct Node {
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node *next) : val(val), next(next) {}
    Node() {
      this->next = nullptr;
      this->val = -1;
    }
  };

 public:

  Node *dummyHead;
  int size;

  /** Initialize your data structure here. */
  MyHashSet() {
    dummyHead = new Node();
    size = 0;
  }

  void add(int key) {
    if (!contains(key)) {
      dummyHead->next = new Node(key, dummyHead->next);
      size += 1;
    }
  }

  void remove(int key) {
    if (!contains(key)) return;
    Node *prev = dummyHead;
    while (prev->next) {
      if (prev->next->val == key) {
        break;
      }
      prev = prev->next;
    }
    if (prev) {
      Node *delNode = prev->next;
      prev->next = delNode->next;
      size--;
      delNode->next = nullptr;
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    Node *curNode = dummyHead->next;
    while (curNode) {
      if (curNode->val == key) {
        return true;
      }
      curNode = curNode->next;
    }
    return false;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

#endif //CPP_0705__SOLUTION1_H_
