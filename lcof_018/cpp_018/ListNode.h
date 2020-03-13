//
// Created by ooooo on 2020/3/13.
//
#ifndef CPP_018__LISTNODE_H_
#define CPP_018__LISTNODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(vector<int> nums) {
    ListNode *dummyHead = new ListNode(0), *cur = dummyHead;
    for (auto &num : nums) {
      cur->next = new ListNode(num);
      cur = cur->next;
    }
    *this = *dummyHead->next;
    dummyHead->next = nullptr;
    delete dummyHead;
  }
};

#endif //CPP_018__LISTNODE_H_
