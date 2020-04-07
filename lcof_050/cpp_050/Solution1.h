//
// Created by ooooo on 2020/4/7.
//
#ifndef CPP_050__SOLUTION1_H_
#define CPP_050__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  char firstUniqChar(string s) {
    unordered_map<char, int> m;
    for (auto &c: s) {
      m[c]++;
    }
    for (auto &c:s) {
      if (m[c] > 1) continue;
      return c;
    }
    return ' ';
  }
};

#endif //CPP_050__SOLUTION1_H_
