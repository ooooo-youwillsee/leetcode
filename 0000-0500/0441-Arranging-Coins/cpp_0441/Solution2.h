//
// Created by ooooo on 2020/1/19.
//
#ifndef CPP_0441__SOLUTION2_H_
#define CPP_0441__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * binary search
 */
class Solution {
 public:
  int arrangeCoins(int n) {
    if (n <= 1) return n;
    long left = 1, right = n, mid = 0, sum = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      sum = (1 + mid) * mid / 2;
      // sum == n 或者 当前的sum小于n,但累计下一个值大于n
      if (sum == n || (sum < n && sum + mid + 1 > n)) {
        return mid;
      } else if (sum > n) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};

#endif //CPP_0441__SOLUTION2_H_
