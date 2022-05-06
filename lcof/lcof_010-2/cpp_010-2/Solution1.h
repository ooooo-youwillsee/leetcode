//
// Created by ooooo on 2020/3/9.
//
#ifndef CPP_010_2__SOLUTION1_H_
#define CPP_010_2__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[n] = dp[n-1] + dp[n-2]
 */
class Solution {
 public:
  int numWays(int n) {
    if (n ==0) return 1;
    if (n == 1 || n == 2) return n;
    int a = 1, b = 2, c = 0;
    for (int i = 3; i <= n; ++i) {
      c = (a + b) % 1000000007;
      a = b;
      b = c;
    }
    return c;
  }
};

#endif //CPP_010_2__SOLUTION1_H_
