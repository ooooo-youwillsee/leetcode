//
// Created by ooooo on 2020/2/22.
//
#ifndef CPP_0240__SOLUTION1_H_
#define CPP_0240__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size(), row = 0, col = n - 1;
    while (row >= 0 && row < m && col >= 0 && col < n) {
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] < target) {
        row++;
      } else {
        col--;
      }
    }
    return false;
  }
};

#endif //CPP_0240__SOLUTION1_H_
