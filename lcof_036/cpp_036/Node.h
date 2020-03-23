//
// Created by ooooo on 2020/3/23.
//
#ifndef CPP_036__NODE_H_
#define CPP_036__NODE_H_

#include <iostream>

using namespace std;

class Node {
 public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

#endif //CPP_036__NODE_H_
