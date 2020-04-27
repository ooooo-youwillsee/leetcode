//
// Created by ooooo on 2020/4/27.
//
#ifndef CPP_067__SOLUTION1_H_
#define CPP_067__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:

  int strToInt(string str) {
    int i = 0;
    for (; i < str.size() && str[i] == ' '; i++) {}
    bool flag = true;
    if (str[i] == '-' || str[i] == '+') flag = str[i++] == '+';
    if (!isdigit(str[i])) return 0;
    long ans = 0;
    while (i < str.size()) {
      if (isdigit(str[i])) {
        ans = ans * 10 + str[i] - '0';
        if (flag && ans > INT_MAX) return INT_MAX;
        if (!flag && -ans < INT_MIN) return INT_MIN;
      } else {
        break;
      }
      i++;
    }
    return flag ? ans : -ans;
  }
};

#endif //CPP_067__SOLUTION1_H_
