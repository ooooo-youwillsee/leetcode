//
// Created by ooooo on 2020/3/11.
//
#ifndef CPP_014_2__SOLUTION1_H_
#define CPP_014_2__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/**
 * greed， 尽可能的划分为3 和 2 ==> 7 = 2*3 +1 = 3 + 2*2
 */
class Solution {
 public:
  int cuttingRope(int n) {
    if (n <= 3) return n - 1;
    int b = n % 3, p = 1000000007;
    long rem = 1, x = 3;
    for (int a = n / 3 - 1; a > 0; a /= 2) {
      if (a % 2 == 1) rem = (rem * x) % p;
      x = (x * x) % p;
    }
    if (b == 0) return (int) (rem * 3 % p);
    if (b == 1) return (int) (rem * 4 % p);
    return (int) (rem * 6 % p);
  }
};

#endif //CPP_014_2__SOLUTION1_H_
