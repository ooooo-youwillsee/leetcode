//
// Created by ooooo on 2020/1/26.
//
#ifndef CPP_0459__SOLUTION1_H_
#define CPP_0459__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    //for (int i = 1; i <= s.size() / 2; ++i) {
    // 从高向低
    for (int i = s.size() / 2; i >= 1; --i) {
      // 子串必须要重复，所以要被整除
      if (s.size() % i != 0) continue;
      bool find = true;
      string target = s.substr(0, i);
      for (int j = i; j < s.size(); j += i) {
        if (target != s.substr(j, i)) {
          find = false;
          break;
        }
      }
      if (find) {
        return true;
      }
    }
    return false;
  }
};

#endif //CPP_0459__SOLUTION1_H_
