//
// Created by ooooo on 2020/3/6.
//
#ifndef CPP_004__SOLUTION2_H_
#define CPP_004__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * O(n^2)
 */
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    for (int i = 0, rows = matrix.size(); i < rows; ++i) {
      for (int j = 0, cols = matrix[0].size(); j < cols; ++j) {
        if (matrix[i][j] == target) return true;
      }
    }
    return false;
  }
};

#endif //CPP_004__SOLUTION2_H_
