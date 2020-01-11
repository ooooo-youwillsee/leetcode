//
// Created by ooooo on 2020/1/11.
//
#ifndef CPP_0447__SOLUTION1_H_
#define CPP_0447__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
 public:

  int distance(vector<int> a, vector<int> b) {
    return pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2);
  }

  int numberOfBoomerangs2(vector<vector<int>> &points) {
    unordered_map<int, int> m;
    int ans = 0;
    for (int i = 0; i < points.size(); ++i) {
      m.clear();
      for (int j = 0; j < points.size(); ++j) {
        if (i == j) continue;
        m[distance(points[i], points[j])]++;
      }
      for (auto &entry: m) {
        if (entry.second >= 2) {
          ans += entry.second * (entry.second - 1);
        }
      }
    }

    return ans;
  }

  int numberOfBoomerangs(vector<vector<int>> &points) {
    unordered_map<int, int> m;
    int ans = 0;
    for (int i = 0; i < points.size(); ++i) {
      m.clear();
      for (int j = 0; j < points.size(); ++j) {
        if (i == j) continue;
        int dis = distance(points[i], points[j]);
        m[dis]++;
        if (m[dis] > 1) {
          // 每添加一个节点，就是添加n-1种排列，再加上可以两两交换（ *2 ）
          ans += 2 * (m[dis] - 1);
        }
      }
    }

    return ans;
  }
};

#endif //CPP_0447__SOLUTION1_H_
