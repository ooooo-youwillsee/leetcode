//
// Created by ooooo on 2020/1/26.
//
#ifndef CPP_0541__SOLUTION1_H_
#define CPP_0541__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    bool flag = true;
    int i = 0;
    // -k => 预留k个空间。
    for (; k <= s.size() && i < s.size() - k; i += k) {
      if (flag) {
        reverse(s.begin() + i, s.begin() + i + k);
      }
      flag = !flag;
    }
    // 最后一个区间，是否需要变换
    if (flag) {
      reverse(s.begin() + i, s.end());
    }
    return s;
  }
};

#endif //CPP_0541__SOLUTION1_H_
