//
// Created by ooooo on 2020/2/22.
//
#ifndef CPP_0238__SOLUTION1_H_
#define CPP_0238__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * left 左边的乘积； right 右边的乘积
 */
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size(), num = 1;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
      left[i] = num;
      num *= nums[i];
    }
    num = 1;
    for (int j = n - 1; j >= 0; --j) {
      right[j] = num;
      num *= nums[j];
    }
    for (int i = 0; i < n; ++i) {
      left[i] = left[i] * right[i];
    }
    return left;
  }
};

#endif //CPP_0238__SOLUTION1_H_
