//
// Created by ooooo on 2020/1/22.
//
#ifndef CPP_0852__SOLUTION1_H_
#define CPP_0852__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int> &A) {
    // left和right 就是要搜索的区间
    int left = 1, right = A.size() - 2;
    while (left < right) {
      int mid = left + (right - left) / 2;
      // 必须要缩小的区间
      if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) {
        left = mid + 1;
      } else if (A[mid - 1] > A[mid] && A[mid] > A[mid - 1]) {
        right = mid - 1;
      } else {
        // 逼近。。
        right = mid;
      }
    }
    return left;
  }
};

#endif //CPP_0852__SOLUTION1_H_
