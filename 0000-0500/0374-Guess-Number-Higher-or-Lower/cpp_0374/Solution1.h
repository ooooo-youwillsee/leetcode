//
// Created by ooooo on 2020/1/18.
//
#ifndef CPP_0374__SOLUTION1_H_
#define CPP_0374__SOLUTION1_H_

#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
  return 6 - num;
}

class Solution {
 public:
  int guessNumber(int n) {
    int left = 1, right = n;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int res = guess(mid);
      if (res == 0) {
        return mid;
      } else if (res > 0) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

#endif //CPP_0374__SOLUTION1_H_
