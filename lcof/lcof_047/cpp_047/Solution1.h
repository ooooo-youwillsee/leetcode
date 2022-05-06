//
// Created by ooooo on 2020/4/3.
//
#ifndef CPP_047__SOLUTION1_H_
#define CPP_047__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dfs timeout
 */
class Solution {
 public:

  void dfs(int i, int j, int sum) {
    if (i >= m || j >= n) return;
    sum += grid[i][j];
    if (i == m - 1 && j == n - 1) {
      ans = max(ans, sum);
      return;
    }
    dfs(i, j + 1, sum);
    dfs(i + 1, j, sum);
  }
  vector<vector<int>> grid;
  int m = 0, n = 0, ans = 0;
  int maxValue(vector<vector<int>> &grid) {
    if (grid.empty()) return 0;
    this->grid = grid;
    this->m = grid.size();
    this->n = grid[0].size();
    dfs(0, 0, 0);
    return ans;
  }
};

#endif //CPP_047__SOLUTION1_H_
