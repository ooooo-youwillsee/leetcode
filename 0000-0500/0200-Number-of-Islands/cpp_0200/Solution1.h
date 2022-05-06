//
// Created by ooooo on 2020/2/19.
//
#ifndef CPP_0200__SOLUTION1_H_
#define CPP_0200__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dfs
 */
class Solution {
 public:

  void dfs(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || mark[i][j])return;
    mark[i][j] = true;
    if (grid[i][j] == '0') return;
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i - 1, j);
  }

  vector<vector<char>> grid;
  vector<vector<bool>> mark;
  int ans = 0, m, n;

  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) return 0;
    this->grid = grid;
    this->m = grid.size();
    this->n = grid[0].size();
    this->mark.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!mark[i][j] && grid[i][j] == '1') {
          ans++;
          dfs(i, j);
        }
      }
    }
    return ans;
  }
};

#endif //CPP_0200__SOLUTION1_H_
