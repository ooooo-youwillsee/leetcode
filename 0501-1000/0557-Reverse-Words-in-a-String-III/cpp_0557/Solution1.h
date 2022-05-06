//
// Created by ooooo on 2020/1/28.
//
#ifndef CPP_0557__SOLUTION1_H_
#define CPP_0557__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    s += " ";
    int i = 0, j = s.find(" ", i);
    while (j != -1) {
      reverse(s.begin() + i, s.begin() + j);
      i = j + 1;
      j = s.find(" ", i);
    }
    return s.substr(0, s.size() - 1);
  }
};

#endif //CPP_0557__SOLUTION1_H_
