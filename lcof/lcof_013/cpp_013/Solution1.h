//
// Created by ooooo on 2020/3/10.
//
#ifndef CPP_013__SOLUTION1_H_
#define CPP_013__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int calc_num(int i, int j) {
    int sum = 0;
    while (i || j) {
      sum += i % 10 + j % 10;
      i /= 10;
      j /= 10;
    }
    return sum;
  }

  bool is_valid(int i, int j) {
    return i >= 0 && i < m && j >= 0 && j < n && !marked[i][j] && calc_num(i, j) <= k;
  }

  int dfs(int i, int j) {
    if (!is_valid(i, j)) return 0;
    int count = 1;
    marked[i][j] = true;
    for (int p = 0; p < 4; ++p) {
      int dx = i + dx_dy[p][0], dy = j + dx_dy[p][1];
      count += dfs(dx, dy);
    }
    return count;
  }

  int m, n, k;
  vector<vector<int>> dx_dy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<bool>> marked;

  int movingCount(int m, int n, int k) {
    this->m = m;
    this->n = n;
    this->k = k;
    this->marked.assign(m, vector<bool>(n, false));
    return dfs(0, 0);
  }
};

#endif //CPP_013__SOLUTION1_H_
