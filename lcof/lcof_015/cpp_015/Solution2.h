//
// Created by ooooo on 2020/3/12.
//
#ifndef CPP_015__SOLUTION2_H_
#define CPP_015__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * 32 次
 */
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      if (n & 1) {
        ans += 1;
      }
      n >>= 1;
    }
    return ans;
  }
};

#endif //CPP_015__SOLUTION2_H_
