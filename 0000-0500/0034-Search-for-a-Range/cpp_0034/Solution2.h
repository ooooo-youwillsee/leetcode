//
// Created by ooooo on 2020/2/9.
//
#ifndef CPP_0034__SOLUTION2_H_
#define CPP_0034__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分法 (找到左边界和右边界)
 */
class Solution {
 public:

  int findBound(vector<int> nums, int target, bool isLeft) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      // isLeft ? 0 : 1 --> 默认向左偏
      int mid = left + (right - left + (isLeft ? 0 : 1)) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        if (isLeft) {
          right = mid;
        } else {
          left = mid;
        }
      }
    }
    return nums[left] == target ? left : -1;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};
    int leftIndex = findBound(nums, target, true);
    if (leftIndex == -1) return {-1, -1};
    return {leftIndex, findBound(nums, target, false)};
  }

};

#endif //CPP_0034__SOLUTION2_H_
