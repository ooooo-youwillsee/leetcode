//
// Created by ooooo on 2020/2/13.
//
#ifndef CPP_0064__SOLUTION2_H_
#define CPP_0064__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 暴力 dfs
 */
class Solution {
 public:

  void dfs(int i, int j, int sum) {
    if (i == m || j == n) return;
    sum += grid[i][j];
    if (i == m - 1 && j == n - 1) {
      min_sum = min(min_sum, sum);
    }
    dfs(i + 1, j, sum);
    dfs(i, j + 1, sum);
  }

  int min_sum = INT_MAX, m, n;
  vector<vector<int>> grid;
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty()) return 0;
    this->grid = grid;
    this->m = grid.size();
    this->n = grid[0].size();
    dfs(0, 0, 0);
    return min_sum;
  }
};

#endif //CPP_0064__SOLUTION2_H_
