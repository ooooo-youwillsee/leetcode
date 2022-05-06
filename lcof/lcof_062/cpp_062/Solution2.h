//
// Created by ooooo on 2020/4/22.
//
#ifndef CPP_062__SOLUTION2_H_
#define CPP_062__SOLUTION2_H_

#include <iostream>
#include <list>

using namespace std;

/**
 *
 */
class Solution {
 public:
  int lastRemaining(int n, int m) {
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      ans = (ans + m) % i;
    }
    return ans;
  }
};

#endif //CPP_062__SOLUTION2_H_
