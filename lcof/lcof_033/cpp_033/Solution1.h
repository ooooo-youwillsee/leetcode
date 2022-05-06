//
// Created by ooooo on 2020/3/21.
//
#ifndef CPP_033__SOLUTION1_H_
#define CPP_033__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  bool help(int l, int r) {
    if (l >= r) return true;
    int i = r - 1;
    while (i >= 0) {
      if (postorder[i] < postorder[r]) {
        for (int j = 0; j < i; ++j) {
          if (postorder[j] > postorder[r]) return false;
        }
        break;
      }
      i--;
    }
    return help(l, i) && help(i + 1, r - 1);
  }
  vector<int> postorder;
  bool verifyPostorder(vector<int> &postorder) {
    if (postorder.empty()) return true;
    this->postorder = postorder;
    return help(0, postorder.size() - 1);
  }
};

#endif //CPP_033__SOLUTION1_H_
