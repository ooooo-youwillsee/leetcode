//
// Created by ooooo on 2020/3/8.
//
#ifndef CPP_010_1__SOLUTION1_H_
#define CPP_010_1__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * F(N) = F(N - 1) + F(N - 2)
 *
 * recursion timeout （有重复计算）
 * O(2^n)
 */
class Solution {
 public:

  long dfs(int n) {
    if (n == 0 || n == 1) return n;
    return dfs(n - 1) + dfs(n - 2);
  }

  int fib(int n) {
    return dfs(n) % 1000000007;
  }
};

#endif //CPP_010_1__SOLUTION1_H_
