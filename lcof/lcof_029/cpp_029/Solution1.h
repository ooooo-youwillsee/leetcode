//
// Created by ooooo on 2020/3/18.
//
#ifndef CPP_029__SOLUTION1_H_
#define CPP_029__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;


class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = 0, count = 0, total = m * n;
    vector<int> ans;

    while (true) {
      while (j < n - count) {
        ans.push_back(matrix[i][j]);
        j++;
      }
      if (ans.size() == total) break;
      // 越界处理 和 重复元素处理
      j--;
      i++;
      while (i < m - count) {
        ans.push_back(matrix[i][j]);
        i++;
      }
      if (ans.size() == total) break;
      i--;
      j--;
      while (j >= count) {
        ans.push_back(matrix[i][j]);
        j--;
      }
      if (ans.size() == total) break;
      j++;
      i--;
      count += 1;
      while (i >= count) {
        ans.push_back(matrix[i][j]);
        i--;
      }
      if (ans.size() == total) break;
      i++;
      j++;
    }
    return ans;
  }
};

#endif //CPP_029__SOLUTION1_H_
