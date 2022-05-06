//
// Created by ooooo on 2020/3/14.
//
#ifndef CPP_020__SOLUTION1_H_
#define CPP_020__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <strings.h>

using namespace std;

/**
 * A[.[B]][e|EC]
 */
class Solution {
 public:

  bool scanUnsignedInteger(string &s, int &i) {
    int j = i;
    while (s[i] >= '0' && s[i] <= '9') i++;
    return i > j;
  }

  bool scanInteger(string &s, int &i) {
    if (s[i] == '+' || s[i] == '-') i++;
    return scanUnsignedInteger(s, i);
  }

  bool isNumber(string s) {
    if (s.empty()) return false;
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    int i = 0;
    bool numeric = scanInteger(s, i);
    if (s[i] == '.') {
      i++;
      numeric = scanUnsignedInteger(s, i) || numeric;
    }
    if (s[i] == 'e' || s[i] == 'E') {
      i++;
      numeric = numeric && scanInteger(s, i);
    }
    return numeric && i == s.size();
  }
};

#endif //CPP_020__SOLUTION1_H_
