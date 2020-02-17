//
// Created by ooooo on 2020/2/17.
//
#ifndef CPP_0142__LISTNODE_H_
#define CPP_0142__LISTNODE_H_

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_0142__LISTNODE_H_
