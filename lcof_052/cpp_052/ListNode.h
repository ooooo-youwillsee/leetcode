//
// Created by ooooo on 2020/4/9.
//
#ifndef CPP_052__LISTNODE_H_
#define CPP_052__LISTNODE_H_

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_052__LISTNODE_H_
