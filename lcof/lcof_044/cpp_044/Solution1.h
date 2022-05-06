//
// Created by ooooo on 2020/3/29.
//
#ifndef CPP_044__SOLUTION1_H_
#define CPP_044__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
 public:

  long countNums(int digit) {
    if (digit == 1) return 10;
    return 9 * powl(10, digit - 1);
  }

  int findNthDigit(int n) {
    int digit = 1;
    while (true) {
      long nums = countNums(digit);
      if (n < nums * digit) return getDigit(n, digit);
      n -= nums * digit;
      digit++;
    }
  }

  int getDigit(int n, int digit) {
    if (digit == 1) return n;
    int base = (int) pow(10, digit - 1) + n / digit;
    return to_string(base)[n % digit] - '0';
  }
};

#endif //CPP_044__SOLUTION1_H_
