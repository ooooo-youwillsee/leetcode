//
// Created by ooooo on 2020/3/15.
//
#ifndef CPP_021__SOLUTION1_H_
#define CPP_021__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 双指针
 */
class Solution {
 public:
  vector<int> exchange(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (true) {
      while (l < r && (nums[l] & 1) == 1) l++;
      while (l < r && (nums[r] & 1) == 0) r--;
      if (l >= r) break;
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
    return nums;
  }
};

#endif //CPP_021__SOLUTION1_H_
