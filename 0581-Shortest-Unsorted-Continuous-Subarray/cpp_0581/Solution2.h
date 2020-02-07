//
// Created by ooooo on 2020/2/7.
//
#ifndef CPP_0581__SOLUTION2_H_
#define CPP_0581__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 *
 */
class Solution {
 public:
  int findUnsortedSubarray(vector<int> &nums) {
    int min_value = INT_MAX, max_value = INT_MIN;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] > nums[i]) {
        min_value = min(min_value, nums[i]);
      }
    }
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1]) {
        max_value = max(max_value, nums[i]);
      }
    }
    int l = 0, r = 0;
    for (l = 0; l < nums.size(); ++l) {
      if (nums[l] > min_value) {
        break;
      }
    }

    for (r = nums.size() - 1; r >= 0; --r) {
      if (nums[r] < max_value) {
        break;
      }
    }
    return r - l < 0 ? 0 : r - l + 1;
  }
};

#endif //CPP_0581__SOLUTION2_H_
