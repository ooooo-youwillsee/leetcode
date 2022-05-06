//
// Created by ooooo on 2020/1/22.
//
#ifndef CPP_1237__SOLUTION2_H_
#define CPP_1237__SOLUTION2_H_

#include "CustomFunction.h"

/**
 * binary search
 */
class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
    vector<vector<int>> ans;
    for (int x = 1; x <= 1000; ++x) {
      int left = 1, right = 1000;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (customfunction.f(x, mid) < z) {
          left = mid + 1;
        } else if (customfunction.f(x, mid) > z) {
          right = mid - 1;
        } else {
          ans.push_back({x, mid});
          break;
        }
      }
    }
    return ans;
  }
};
#endif //CPP_1237__SOLUTION2_H_
