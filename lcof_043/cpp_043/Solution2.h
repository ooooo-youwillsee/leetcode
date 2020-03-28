//
// Created by ooooo on 2020/3/28.
//
#ifndef CPP_043__SOLUTION2_H_
#define CPP_043__SOLUTION2_H_

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
 public:

  int dfs(int n) {
    if (n <= 0) return 0;
    string s = to_string(n);
    int high = s[0] - '0';
    int pow = powl(10, s.length() - 1);
    int last = n - high * pow;
    if (high == 1) {
      return dfs(pow - 1) + dfs(last) + last + 1;
    } else {
      return pow + high * dfs(pow - 1) + dfs(last);
    }
  }
  int countDigitOne(int n) {
    return dfs(n);
  }
};

#endif //CPP_043__SOLUTION2_H_
