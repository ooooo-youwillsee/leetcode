//
// Created by ooooo on 2020/2/18.
//
#ifndef CPP_0148__LISTNODE_H_
#define CPP_0148__LISTNODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(vector<int> nums) : val(nums[0]), next(NULL) {
    ListNode *cur = this;
    for (int i = 1; i < nums.size(); ++i) {
      cur->next = new ListNode(nums[i]);
      cur = cur->next;
    }
  }
};

#endif //CPP_0148__LISTNODE_H_
