//
// Created by ooooo on 2020/1/19.
//
#ifndef CPP_0441__SOLUTION1_H_
#define CPP_0441__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * loop
 */
class Solution {
 public:
  int arrangeCoins(int n) {
    long long sum = 0, i = 0;
    while (true) {
      if (sum == n) return i;
      if (sum > n) return i - 1;
      sum += (++i);
    }
  }
};

#endif //CPP_0441__SOLUTION1_H_
