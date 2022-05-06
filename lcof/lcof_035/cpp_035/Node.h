//
// Created by ooooo on 2020/3/22.
//
#ifndef CPP_035__NODE_H_
#define CPP_035__NODE_H_

#include <iostream>

using namespace std;

class Node {
 public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

#endif //CPP_035__NODE_H_
