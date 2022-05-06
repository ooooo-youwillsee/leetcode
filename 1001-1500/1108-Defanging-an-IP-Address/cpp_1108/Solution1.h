//
// Created by ooooo on 2020/2/2.
//
#ifndef CPP_1108__SOLUTION1_H_
#define CPP_1108__SOLUTION1_H_

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
 public:
  string defangIPaddr(string address) {
    string target = "[.]";
    stringstream ss;
    for (auto &c: address) {
      if (c == '.') {
        ss << target;
      } else {
        ss << c;
      }
    }
    return ss.str();
  }
};

#endif //CPP_1108__SOLUTION1_H_
