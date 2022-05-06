//
// Created by ooooo on 2020/2/3.
//
#ifndef CPP_1221__SOLUTION1_H_
#define CPP_1221__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  int balancedStringSplit(string s) {
    int R_count = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'R') R_count++;
      else if (s[i] == 'L') R_count--;
      if (R_count == 0) ans += 1;
    }
    return ans;
  }
};

#endif //CPP_1221__SOLUTION1_H_
