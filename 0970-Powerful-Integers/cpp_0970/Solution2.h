//
// Created by ooooo on 2020/1/17.
//
#ifndef CPP_0970__SOLUTION2_H_
#define CPP_0970__SOLUTION2_H_

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * map缓存，2^20 > 1000000
 */
class Solution {
 public:

  unordered_map<int, vector<int>> m;

  int calcMaxBound(int x, int bound) {
    if (x == 1) {
      m[x] = vector<int>(bound, 1);
      return bound;
    }
    int ans = 0, sum = 1;
    while (sum <= bound) {
      m[x].push_back(sum);
      ans++;
      sum *= x;
    }
    return ans;
  }

  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> ans;
    m[x] = m[y] = {};
    int xMax = calcMaxBound(x, bound), yMax = calcMaxBound(y, bound);
    // 2^20 > 1000000
    for (int i = 0; i < xMax && i < 20; ++i) {
      for (int j = 0; j < yMax && j < 20; ++j) {
        int sum = m[x][i] + m[y][j];
        if (sum <= bound) {
          ans.insert(sum);
        }
      }
    }
    return vector<int>(ans.begin(), ans.end());
  }
};

#endif //CPP_0970__SOLUTION2_H_
