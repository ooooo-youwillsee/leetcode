//
// Created by ooooo on 2020/1/17.
//
#ifndef CPP_0278__SOLUTION1_H_
#define CPP_0278__SOLUTION1_H_

#include <iostream>

using namespace std;

bool isBadVersion(int version) {
  return version >= 4;
}

class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left <= right) {
      int mid = left + ((right - left) / 2);
      if (isBadVersion(mid)) {
        if (mid == 1 || (!isBadVersion(mid - 1) && mid > 0)) return mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};

#endif //CPP_0278__SOLUTION1_H_
