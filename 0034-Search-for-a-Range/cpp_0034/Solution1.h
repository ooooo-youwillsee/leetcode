//
// Created by ooooo on 2020/2/9.
//
#ifndef CPP_0034__SOLUTION1_H_
#define CPP_0034__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分法
 */
class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};
    int left = 0, right = (int) nums.size() - 1, mid = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        break;
      }
    }
    if (nums[mid] != target) return {-1, -1};
    left = mid - 1, right = mid + 1;
    while (left >= 0 && nums[left] == nums[mid]) left--;
    while (right < nums.size() && nums[right] == nums[mid]) right++;
    return {left + 1, right - 1};
  }
};

#endif //CPP_0034__SOLUTION1_H_
