//
// Created by ooooo on 2020/1/17.
//
#ifndef CPP_0970__SOLUTION1_H_
#define CPP_0970__SOLUTION1_H_

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {

 public:

  int calcMaxBound(int x, int bound) {
    if (x == 1) return bound;
    int ans = 0, sum = 1;
    while (sum <= bound) {
      ans++;
      sum *= x;
    }
    return ans;
  }

  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> ans;
    for (int i = 0; i < calcMaxBound(x, bound); ++i) {
      for (int j = 0; j < calcMaxBound(y, bound); ++j) {
        int sum = pow(x, i) + pow(y, j);
        if (sum <= bound) {
          ans.insert(sum);
        }
      }
    }
    return vector<int>(ans.begin(), ans.end());
  }
};

#endif //CPP_0970__SOLUTION1_H_
