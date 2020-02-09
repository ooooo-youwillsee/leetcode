//
// Created by ooooo on 2020/2/9.
//
#ifndef CPP_0033__SOLUTION2_H_
#define CPP_0033__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分法 (两次， 第一次查找分隔点，第二次查找目标值) ???
 */
class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
        left = mid + 1;
      else
        right = mid;
    }
    return left == right && nums[left] == target ? left : -1;
  }

};

#endif //CPP_0033__SOLUTION2_H_
