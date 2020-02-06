//
// Created by ooooo on 2020/2/6.
//
#ifndef CPP_0461__SOLUTION1_H_
#define CPP_0461__SOLUTION1_H_

#include <iostream>
#include <sstream>

using namespace std;

/**
 * 将数字转化为字符串，然后^操作
 */
class Solution {
 public:
  string help(int n) {
    stringstream ss;
    int i = 0;
    while (n) {
      ss << n % 2;
      i += 1;
      n /= 2;
    }
    ss << string(32 - i, '0');
    return ss.str();
  }
  int hammingDistance(int x, int y) {
    string x_str = help(x);
    string y_str = help(y);
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      if ((x_str[i] ^ y_str[i]) == 1) {
        ans += 1;
      }
    }
    return ans;
  }
};

#endif //CPP_0461__SOLUTION1_H_
