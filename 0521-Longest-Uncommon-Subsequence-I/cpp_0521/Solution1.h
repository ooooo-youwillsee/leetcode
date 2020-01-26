//
// Created by ooooo on 2020/1/26.
//
#ifndef CPP_0521__SOLUTION1_H_
#define CPP_0521__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  int findLUSlength(string a, string b) {
    if (a.size() > b.size()) return a.size();
    else if (a.size() < b.size()) return b.size();
    else if (a == b) return -1;
    return a.size();
  }
};

#endif //CPP_0521__SOLUTION1_H_
