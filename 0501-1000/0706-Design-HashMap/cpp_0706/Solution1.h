//
// Created by ooooo on 2020/1/14.
//
#ifndef CPP_0706__SOLUTION1_H_
#define CPP_0706__SOLUTION1_H_

class MyHashMap {

 private:

  struct Node {
    int key;
    int value;
    Node *next;
    Node(int key, int value, Node *next) : key(key), value(value), next(next) {}
    Node() {
      this->next = nullptr;
    }
  };

  Node *dummyHead;
  int size;

 public:
  /** Initialize your data structure here. */
  MyHashMap() {
    this->dummyHead = new Node();
    this->size = 0;
  }

  bool contains(int key) {
    Node *curNode = dummyHead->next;
    while (curNode) {
      if (curNode->key == key) return true;
      curNode = curNode->next;
    }
    return false;
  }

  Node *getNode(int key) {
    Node *curNode = dummyHead->next;
    while (curNode) {
      if (curNode->key == key) return curNode;
      curNode = curNode->next;
    }
    return nullptr;
  }

  /** value will always be non-negative. */
  void put(int key, int value) {
    Node *node = getNode(key);
    if (node) {
      node->value = value;
    } else {
      dummyHead->next = new Node(key, value, dummyHead->next);
      size++;
    }
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    Node *node = getNode(key);
    if (node) {
      return node->value;
    } else {
      return -1;
    }
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    bool find = false;
    Node *prev = dummyHead;
    while (prev->next) {
      if (prev->next->key == key) {
        find = true;
        break;
      }
      prev = prev->next;
    }

    if (prev && find) {
      Node *delNode = prev->next;
      prev->next = delNode->next;
      size--;
      delNode->next = nullptr;
    }
  }
};

#endif //CPP_0706__SOLUTION1_H_
