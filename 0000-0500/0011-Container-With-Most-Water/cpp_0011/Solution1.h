//
// Created by ooooo on 2020/2/6.
//
#ifndef CPP_0011__SOLUTION1_H_
#define CPP_0011__SOLUTION1_H_

#include <iostream>
#include <vector>

/**
 * 暴力破解
 */
using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int ans = 0;
    for (int i = 0; i < height.size(); ++i) {
      for (int j = i + 1; j < height.size(); ++j) {
        ans = max(ans, min(height[i], height[j])*(j - i));
      }
    }
    return ans;
  }
};

#endif //CPP_0011__SOLUTION1_H_
