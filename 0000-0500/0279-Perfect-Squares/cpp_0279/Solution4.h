//
// Created by ooooo on 2020/2/23.
//
#ifndef CPP_0279__SOLUTION4_H_
#define CPP_0279__SOLUTION4_H_

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * bfs 这一题相当于 查找最短路径（n -> 0）
 */
class Solution {
 public:

  int numSquares(int n) {
    unordered_set<int> set;
    for (int i = int(sqrt(n)); i >= 1; --i) {
      set.insert(i * i);
    }
    int level = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
      level++;
      for (int i = 0, len = q.size(); i < len; ++i) {
        n = q.front();
        q.pop();
        if (set.count(n)) return level;
        for (auto &num: set) {
          if (n >= num) {
            q.push(n - num);
          }
        }
      }
    }
    return level;
  }
};

#endif //CPP_0279__SOLUTION4_H_
