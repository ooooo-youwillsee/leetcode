//
// Created by ooooo on 2020/2/11.
//
#ifndef CPP_0048__SOLUTION1_H_
#define CPP_0048__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> data(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        data[i][j] = matrix[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[j][n - 1 - i] = data[i][j];
      }
    }
  }
};

#endif //CPP_0048__SOLUTION1_H_
