//
// Created by ooooo on 2020/1/19.
//
#ifndef CPP_0441__SOLUTION3_H_
#define CPP_0441__SOLUTION3_H_

#include <iostream>
#include <cmath>

using namespace std;

/**
 * 数学公式求解  k(k+1) /2 = n ==> 其正数解为 k = sqrt(2n+1/4) - 1/2
 *
 * => k = sqrt(2) * sqrt(n + 1/8) - 1/2
 */
class Solution {
 public:
  int arrangeCoins(int n) {
    return int(sqrt(2) * sqrt(n + 0.125) - 0.5);
  }
};

#endif //CPP_0441__SOLUTION3_H_
