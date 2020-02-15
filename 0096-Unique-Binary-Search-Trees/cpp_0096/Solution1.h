//
// Created by ooooo on 2020/2/15.
//
#ifndef CPP_0096__SOLUTION1_H_
#define CPP_0096__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * f(i，n) 表示以 i 为根，长度为 n 的个数 ( 1 <= i <= n)
 * G(n) 表示长度为 n 的总个数
 * 即： G(n) = f(1, n) + f(2, n) +...+ f(n, n)
 * 而  f(i, n) = G(i-1) * G(n-i)
 *
 * ==> G(n) = G(0) * G(n-1) + G(1) * G(n-2) +...+ G(n-1) * G(0)
 */
class Solution {
 public:
  int numTrees(int n) {
    vector<int> g(n + 1);
    g[0] = g[1] = 1;
    for (int k = 2; k <= n; ++k) {
      for (int i = 1; i <= k; ++i) {
        g[k] += g[i - 1] * g[k - i];
      }
    }
    return g[n];
  }
};

#endif //CPP_0096__SOLUTION1_H_
