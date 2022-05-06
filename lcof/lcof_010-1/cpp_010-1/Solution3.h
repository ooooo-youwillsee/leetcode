//
// Created by ooooo on 2020/3/8.
//
#ifndef CPP_010_1__SOLUTION3_H_
#define CPP_010_1__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * F(N) = F(N - 1) + F(N - 2)
 *
 * dp
 *
 * O(n)
 */
class Solution {
 public:
  /*int fib(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    return dp[n];
  }*/

  int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; ++i) {
      c = (a + b) % 1000000007;
      a = b;
      b = c;
    }
    return c;
  }
};

#endif //CPP_010_1__SOLUTION3_H_
