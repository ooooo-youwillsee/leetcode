//
// Created by ooooo on 2020/3/6.
//
#ifndef CPP_004__SOLUTION1_H_
#define CPP_004__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * O(m+n)
 */
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      int num = matrix[i][j];
      if (target > num) {
        i++;
      } else if (target < num) {
        j--;
      } else {
        return true;
      }
    }
    return false;
  }
};

#endif //CPP_004__SOLUTION1_H_
