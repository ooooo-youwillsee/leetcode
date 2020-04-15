//
// Created by ooooo on 2020/4/15.
//
#ifndef CPP_057__SOLUTION1_H_
#define CPP_057__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    auto l = nums.begin(), r = nums.end() - 1;
    if (it != nums.end()) r = it - 1;
    while (l != r) {
      int ans = *l + *r;
      if (ans == target) return {*l, *r};
      else if (ans < target) l++;
      else r--;
    }
    return {};
  }
};

#endif //CPP_057__SOLUTION1_H_
