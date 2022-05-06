//
// Created by ooooo on 2020/1/28.
//
#ifndef CPP_0551__SOLUTION1_H_
#define CPP_0551__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  bool checkRecord(string s) {
    int A_count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'A') A_count++;
      if (A_count > 1) return false;
      if (i > s.size() - 3) continue;
      if (s[i] == s[i + 1] && s[i + 1] == s[i + 2] && s[i + 2] == 'L') return false;
    }
    return true;
  }
};

#endif //CPP_0551__SOLUTION1_H_
