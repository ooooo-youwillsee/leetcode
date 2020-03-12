//
// Created by ooooo on 2020/3/12.
//
#ifndef CPP_016__SOLUTION3_H_
#define CPP_016__SOLUTION3_H_

#include <iostream>

using namespace std;

/**
 * o(logN)
 */
class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 0) return 0;
    double ans = 1.0;
    long b = n;
    if (b < 0) {
      x = 1 / x;
      b = -b;
    }
    while (b) {
      if (b & 1) ans *= x;
      x *= x;
      b >>= 1;
    }
    return ans;
  }
};

#endif //CPP_016__SOLUTION3_H_
