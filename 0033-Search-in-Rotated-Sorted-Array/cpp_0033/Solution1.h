//
// Created by ooooo on 2020/2/9.
//
#ifndef CPP_0033__SOLUTION1_H_
#define CPP_0033__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分法 (一次)
 */
class Solution {
 public:
  int search(vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      if (nums[left] < nums[mid]) {
        // 左边升序
        if (target <= nums[mid] && target >= nums[left]) {
          right = mid - 1;
        } else {
          left = mid;
        }
      } else if (nums[left] > nums[mid]) {
        // 右边升序
        if (target <= nums[right] && target >= nums[mid]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      } else {
        // mid == left
        left = mid + 1;
      }
    }
    return nums[left] == target ? left : -1;
  }
};

#endif //CPP_0033__SOLUTION1_H_
