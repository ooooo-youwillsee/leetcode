//
// Created by ooooo on 2020/2/24.
//
#ifndef CPP_0300__SOLUTION2_H_
#define CPP_0300__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分法
 * 每一循环，尽量把小的放进去
 */
class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) return n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
      auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
      if (it == vec.end()) {
        vec.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return vec.size();
  }
};

#endif //CPP_0300__SOLUTION2_H_
