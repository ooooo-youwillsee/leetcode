//
// Created by ooooo on 2020/3/21.
//
#ifndef CPP_033__SOLUTION2_H_
#define CPP_033__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  bool help(int l, int r) {
    if (l >= r) return true;
    int left = 0;
    for (; left < r; ++left) {
      if (postorder[left] > postorder[r]) break;
    }
    for (int right = left; right < r; ++right) {
      if (postorder[right] < postorder[r]) return false;
    }
    return help(l, left - 1) && help(left, r - 1);
  }
  vector<int> postorder;
  bool verifyPostorder(vector<int> &postorder) {
    if (postorder.empty()) return true;
    this->postorder = postorder;
    return help(0, postorder.size() - 1);
  }
};

#endif //CPP_033__SOLUTION2_H_
