//
// Created by ooooo on 2020/2/22.
//
#ifndef CPP_0238__SOLUTION2_H_
#define CPP_0238__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * ans先计算左边的, ans[j] = ans[j](原先左边的) * num (当前右边的)
 */
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size(), num = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = num;
      num *= nums[i];
    }
    num = 1;
    for (int j = n - 1; j >= 0; --j) {
      ans[j] *= num;
      num *= nums[j];
    }
    return ans;
  }
};

#endif //CPP_0238__SOLUTION2_H_
