//
// Created by ooooo on 2020/1/22.
//
#ifndef CPP_1237__SOLUTION1_H_
#define CPP_1237__SOLUTION1_H_

#include "CustomFunction.h"

/**
 * 暴力破解
 */
class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
    vector<vector<int>> ans;
    for (int x = 1; x <= 1000; ++x) {
      for (int y = 1; y <= 1000; ++y) {
        if (customfunction.f(x, y) == z) {
          ans.push_back({x, y});
        }
      }
    }
    return ans;
  }
};
#endif //CPP_1237__SOLUTION1_H_
