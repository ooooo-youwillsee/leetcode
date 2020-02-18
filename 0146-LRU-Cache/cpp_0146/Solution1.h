//
// Created by ooooo on 2020/2/18.
//
#ifndef CPP_0146__SOLUTION1_H_
#define CPP_0146__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 要删除的节点在尾节点
 */
class LRUCache {

 private:
  struct Node {
    Node *prev, *next;
    int key, value;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
  };
  unordered_map<int, Node *> map;
  int size, capacity;
  Node *head, *tail;

 public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }

  void addNode(Node *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(Node *node) {
    removeNode(node);
    addNode(node);
  }

  Node *popTail() {
    Node *node = tail->prev;
    removeNode(node);
    return node;
  }

  int get(int key) {
    Node *node = map[key];
    if (!node) return -1;
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    Node *node = map[key];
    if (node) {
      node->value = value;
      moveToHead(node);
    } else {
      node = new Node(key, value);
      map[key] = node;
      addNode(node);
      ++size;
      if (size > capacity) {
        size--;
        map.erase(popTail()->key);
      }
    }
  }

};

#endif //CPP_0146__SOLUTION1_H_
