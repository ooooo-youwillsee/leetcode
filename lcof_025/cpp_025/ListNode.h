//
// Created by ooooo on 2020/3/16.
//
#ifndef CPP_025__LISTNODE_H_
#define CPP_025__LISTNODE_H_

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_025__LISTNODE_H_
