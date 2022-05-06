//
// Created by ooooo on 2020/1/17.
//
#ifndef CPP_0367__SOLUTION2_H_
#define CPP_0367__SOLUTION2_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num < 2) return true;

    long x = num / 2;
    while (x * x > num) {
      x = (x + num / x) / 2;
    }
    return x * x == num;
  }
};

#endif //CPP_0367__SOLUTION2_H_
