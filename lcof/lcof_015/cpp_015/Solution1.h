//
// Created by ooooo on 2020/3/12.
//
#ifndef CPP_015__SOLUTION1_H_
#define CPP_015__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      ans += 1;
      n &= (n - 1);
    }
    return ans;
  }
};

#endif //CPP_015__SOLUTION1_H_
