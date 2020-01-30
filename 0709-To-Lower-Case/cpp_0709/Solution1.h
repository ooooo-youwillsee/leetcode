//
// Created by ooooo on 2020/1/30.
//
#ifndef CPP_0709__SOLUTION1_H_
#define CPP_0709__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  string toLowerCase(string str) {
    for (int i = 0; i < str.size(); ++i) {
      str[i] = tolower(str[i]);
    }
    return str;
  }
};

#endif //CPP_0709__SOLUTION1_H_
