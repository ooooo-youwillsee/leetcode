//
// Created by ooooo on 2020/1/17.
//
#ifndef CPP_0367__SOLUTION1_H_
#define CPP_0367__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * int * int 越界
 */
class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num < 2) return true;
    long left = 2, right = num / 2;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long sum = mid * mid;
      if (sum == num) {
        return true;
      } else if (sum < num) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};

#endif //CPP_0367__SOLUTION1_H_
