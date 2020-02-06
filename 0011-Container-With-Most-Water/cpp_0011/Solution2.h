//
// Created by ooooo on 2020/2/6.
//
#ifndef CPP_0011__SOLUTION2_H_
#define CPP_0011__SOLUTION2_H_

#include <iostream>
#include <vector>

/**
 * 双指针
 */
using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int ans = 0, left = 0, right = height.size() - 1;
    while (left < right) {
      int h = 0, w = right - left;
      if (height[left] <= height[right]) {
        h = height[left];
        left++;
      } else {
        h = height[right];
        right--;
      }
      ans = max(ans, h * w);
    }
    return ans;
  }
};

#endif //CPP_0011__SOLUTION2_H_
