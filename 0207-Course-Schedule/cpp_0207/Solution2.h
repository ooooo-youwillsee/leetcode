//
// Created by ooooo on 2020/2/19.
//
#ifndef CPP_0207__SOLUTION2_H_
#define CPP_0207__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 拓扑排序
 */
class Solution {
 public:

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> indegrees(numCourses, 0);
    vector<vector<int>> adjacency(numCourses, vector<int>());
    for (auto &item: prerequisites) {
      indegrees[item[0]] += 1;
      adjacency[item[1]].push_back(item[0]);
    }
    queue<int> q;
    for (int i = 0; i < indegrees.size(); ++i) {
      if (indegrees[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int j = q.front();
      q.pop();
      numCourses--;
      for (auto &k : adjacency[j]) {
        if (--indegrees[k] == 0) q.push(k);
      }
    }
    return numCourses == 0;
  }
};

#endif //CPP_0207__SOLUTION2_H_
