//
// Created by ooooo on 2020/2/11.
//
#ifndef CPP_0048__SOLUTION2_H_
#define CPP_0048__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i <= n / 2; i++)
      for (int j = i; j < n - 1 - i; j++) {
        int t = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = t;
      }
  }
};

#endif //CPP_0048__SOLUTION2_H_
