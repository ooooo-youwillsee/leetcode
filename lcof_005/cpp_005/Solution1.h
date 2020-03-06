//
// Created by ooooo on 2020/3/6.
//
#ifndef CPP_005__SOLUTION1_H_
#define CPP_005__SOLUTION1_H_

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    stringstream ss;
    for (auto &c: s) {
      if (c == ' ') ss << "%20";
      else ss << c;
    }
    return ss.str();
  }
};

#endif //CPP_005__SOLUTION1_H_
