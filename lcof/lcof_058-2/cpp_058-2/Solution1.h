//
// Created by ooooo on 2020/4/19.
//
#ifndef CPP_058_2__SOLUTION1_H_
#define CPP_058_2__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    return s.substr(n, s.size() - n) + s.substr(0, n);
  }
};

#endif //CPP_058_2__SOLUTION1_H_
