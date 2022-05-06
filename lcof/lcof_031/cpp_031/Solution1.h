//
// Created by ooooo on 2020/3/19.
//
#ifndef CPP_031__SOLUTION1_H_
#define CPP_031__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    for (int i = 0, j = 0, len = popped.size(); i < len;) {
      int pop_val = popped[i];
      while (s.empty() || s.top() != pop_val) {
        if (j == len) return false;
        s.push(pushed[j++]);
      }
      s.pop();
      i++;
    }
    return true;
  }
};

#endif //CPP_031__SOLUTION1_H_
