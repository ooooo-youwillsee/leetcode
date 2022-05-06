//
// Created by ooooo on 2020/2/7.
//
#ifndef CPP_0581__SOLUTION1_H_
#define CPP_0581__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 *双指针
 */
class Solution {
 public:
  int findUnsortedSubarray(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    bool find_left = false, find_right = false;
    while (left <= right) {
      for (int i = left + 1; i <= right; ++i) {
        if (nums[i] < nums[left]) {
          find_left = true;
          break;
        }
      }
      if (find_left) break;
      left += 1;
    }

    while (left <= right) {
      for (int i = right - 1; i >= left; --i) {
        if (nums[i] > nums[right]) {
          find_right = true;
          break;
        }
      }
      if (find_right) break;
      right -= 1;
    }
    return right - left + 1;
  }
};

#endif //CPP_0581__SOLUTION1_H_
