//
// Created by ooooo on 2020/3/12.
//
#ifndef CPP_016__SOLUTION2_H_
#define CPP_016__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * o(logN)
 */
class Solution {
 public:

  double help(double x, long n) {
    if (n == 1) return x;
    return n & 1 ? x * help(x * x, n / 2) : help(x * x, n / 2);
  }

  double myPow(double x, int n) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    return n < 0 ? 1.0 / help(x, (long) n * -1.0) : help(x, (long) n);
  }
};

#endif //CPP_016__SOLUTION2_H_
