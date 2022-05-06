//
// Created by ooooo on 2020/2/19.
//
#ifndef CPP_0207__SOLUTION1_H_
#define CPP_0207__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dfs + 邻接矩阵
 */
class Solution {
 public:

  vector<vector<bool>> graph;
  // 1 表示已访问， -1 表示在上次 dfs 中已经访问过，说明这个节点没有问题， 0 表示没有访问过
  vector<int> mark;
  int n;

  bool dfs(int i) {
    if (mark[i] == -1) return true;
    if (mark[i] == 1) return false;
    mark[i] = 1;
    for (int j = 0; j < n; ++j) {
      if (graph[i][j] && !dfs(j)) return false;
    }
    mark[i] = -1;
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    n = numCourses;
    graph.assign(n, vector<bool>(n, false));
    mark.assign(n, 0);
    for (auto &vec: prerequisites) {
      graph[vec[0]][vec[1]] = true;
    }
    for (int i = 0; i < numCourses; ++i) {
      if (!dfs(i)) return false;
    }
    return true;
  }
};

#endif //CPP_0207__SOLUTION1_H_
