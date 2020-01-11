//
// Created by ooooo on 2020/1/11.
//
#ifndef CPP_0463__SOLUTION1_H_
#define CPP_0463__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 分别计算每一个节点的边数
 */
class Solution {
 public:

  int help(vector<vector<int>> &grid, int i, int j) {
    if (grid[i][j] == 0) return 0;
    int ans = 0;
    if (i == 0 || grid[i - 1][j] == 0) ans++;
    if (j == 0 || grid[i][j - 1] == 0) ans++;
    if (j == grid[i].size() - 1 || grid[i][j + 1] == 0) ans++;
    if (i == grid.size() - 1 || grid[i + 1][j] == 0) ans++;
    return ans;
  }

  int islandPerimeter(vector<vector<int>> &grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        ans += help(grid, i, j);
      }
    }
    return ans;
  }
};

#endif //CPP_0463__SOLUTION1_H_
