//
// Created by ooooo on 2020/3/28.
//
#ifndef CPP_043__SOLUTION1_H_
#define CPP_043__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * timeout
 */
class Solution {
 public:

  int count1(int n) {
    int count = 0;
    while (n) {
      if (n % 10 == 1) count++;
      n /= 10;
    }
    return count;
  }
  int countDigitOne(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += count1(i);
    }
    return ans;
  }
};

#endif //CPP_043__SOLUTION1_H_
