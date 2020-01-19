//
// Created by ooooo on 2020/1/19.
//
#ifndef CPP_0704__SOLUTION1_H_
#define CPP_0704__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

#endif //CPP_0704__SOLUTION1_H_
