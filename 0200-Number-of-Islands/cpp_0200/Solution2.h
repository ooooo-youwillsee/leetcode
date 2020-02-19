//
// Created by ooooo on 2020/2/19.
//
#ifndef CPP_0200__SOLUTION2_H_
#define CPP_0200__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 并查集
 */
class Solution {

 private:

  struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    int count = 0;

    UnionFind(vector<vector<char>> &grid) {
      int m = grid.size(), n = grid[0].size();
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            parent.push_back(i * n + j);
            count += 1;
          } else {
            parent.push_back(-1);
          }
          rank.push_back(1);
        }

      }
    }

    // path compression
    int find(int p) {
      if (p != parent[p]) {
        parent[p] = find(parent[p]);
      }
      return parent[p];
    }

    void unionElements(int p, int q) {
      int pRoot = find(p);
      int qRoot = find(q);
      if (pRoot == qRoot) return;
      if (rank[pRoot] < rank[qRoot]) {
        parent[pRoot] = qRoot;
      } else if (rank[pRoot] > rank[qRoot]) {
        parent[qRoot] = pRoot;
      } else {
        parent[pRoot] = qRoot;
        rank[qRoot] += 1;
      }
      count--;
    }
  };

 public:

  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    UnionFind uf(grid);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          grid[i][j] = '0';
          if (j < n - 1 && grid[i][j + 1] == '1') {
            uf.unionElements(i * n + j, i * n + j + 1);
          }
          if (j > 0 && grid[i][j - 1] == '1') {
            uf.unionElements(i * n + j, i * n + j - 1);
          }
          if (i < m - 1 && grid[i + 1][j] == '1') {
            uf.unionElements(i * n + j, (i + 1) * n + j);
          }
          if (i > 0 && grid[i - 1][j] == '1') {
            uf.unionElements(i * n + j, (i - 1) * n + j);
          }
        }
      }
    }
    return uf.count;
  }
};

#endif //CPP_0200__SOLUTION2_H_
