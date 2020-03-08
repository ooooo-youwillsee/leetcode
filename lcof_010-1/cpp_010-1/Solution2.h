//
// Created by ooooo on 2020/3/8.
//
#ifndef CPP_010_1__SOLUTION2_H_
#define CPP_010_1__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * F(N) = F(N - 1) + F(N - 2)
 *
 * recursion + memo
 *
 */
class Solution {
 public:

  unsigned long dfs(int n) {
    if (memo.count(n)) return memo[n];
    if (n == 0 || n == 1) return n;
    return memo[n] = (dfs(n - 1) + dfs(n - 2)) % 1000000007;
  }

  unordered_map<int, unsigned long> memo;
  int fib(int n) {
    return dfs(n);
  }
};

#endif //CPP_010_1__SOLUTION2_H_
