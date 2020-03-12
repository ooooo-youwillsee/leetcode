//
// Created by ooooo on 2020/3/12.
//
#ifndef CPP_016__SOLUTION1_H_
#define CPP_016__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * o(n) timeout
 */
class Solution {
 public:
  double myPow(double x, int n) {
    double ans = 1.0;
    if (n < 0) return 1.0 / myPow(x, -n);
    while (n) {
      ans *= x;
      n--;
    }
    return ans;
  }
};

#endif //CPP_016__SOLUTION1_H_
