//
// Created by ooooo on 2020/2/18.
//
#ifndef CPP_0146__SOLUTION2_H_
#define CPP_0146__SOLUTION2_H_

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 要删除的节点在头结点
 */
class LRUCache {

 private:
  struct Node {
    Node *prev, *next;
    int key, value;
    Node() {}
    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
  };
  unordered_map<int, Node *> map;
  int size, capacity;
  Node *head, *tail;

 public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    size = 0;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    Node *n = visited(key);
    return n ? n->value : -1;
  }

  // m -> n -> p
  Node *visited(int key) {
    if (!map.count(key)) return nullptr;
    Node *n = map[key], *m = n->prev, *p = n->next;
    m->next = p;
    p->prev = m;
    n->prev = n->next = nullptr;
    moveTail(n);
    return n;
  }

  void moveTail(Node *n) {
    tail->prev->next = n;
    n->prev = tail->prev;
    n->next = tail;
    tail->prev = n;
  }

  void put(int key, int value) {
    Node *n = visited(key);
    if (!n) {
      n = new Node(key, value);
      size++;
      map[key] = n;
      moveTail(n);
    } else {
      n->value = value;
    }
    if (size > capacity) {
      // remove
      Node *r = head->next;
      r->next->prev = head;
      head->next = r->next;
      r->next = r->prev = nullptr;
      map.erase(r->key);
      size--;
    }
  }
};

#endif //CPP_0146__SOLUTION2_H_
