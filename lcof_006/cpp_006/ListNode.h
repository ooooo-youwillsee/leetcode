//
// Created by ooooo on 2020/3/7.
//
#ifndef CPP_006__LISTNODE_H_
#define CPP_006__LISTNODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(vector<int> nums) {
    if (nums.empty()) return;
    this->val = nums[0];
    this->next = nullptr;
    ListNode *cur = this;
    for (int i = 1, len = nums.size(); i < len; ++i) {
      cur->next = new ListNode(nums[i]);
      cur = cur->next;
    }
  }
};

#endif //CPP_006__LISTNODE_H_
