//
// Created by ooooo on 2020/1/23.
//
#ifndef CPP_0083__LISTNODE_H_
#define CPP_0083__LISTNODE_H_

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_0083__LISTNODE_H_
