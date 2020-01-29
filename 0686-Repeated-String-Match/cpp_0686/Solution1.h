//
// Created by ooooo on 2020/1/29.
//
#ifndef CPP_0686__SOLUTION1_H_
#define CPP_0686__SOLUTION1_H_

#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    int i = B.size() % A.size() == 0 ? B.size() / A.size() : B.size() / A.size() + 1;
    string s = "";
    for (int j = 0; j <= i + 1; ++j) {
      // 在循环体内，需要加+1，比较最后一次
      if (j >= i && s.find(B) != -1) {
        return j;
      }
      s += A;
    }
    return -1;
  }
};

#endif //CPP_0686__SOLUTION1_H_
