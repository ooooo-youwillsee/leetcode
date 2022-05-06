//
// Created by ooooo on 2020/4/9.
//
#ifndef CPP_053_1__SOLUTION3_H_
#define CPP_053_1__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int low_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        if (mid == 0) return mid;
        if (nums[mid - 1] != target) return mid;
        else r = mid - 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  }

  int up_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        if (mid == nums.size() - 1) return mid;
        if (nums[mid + 1] != target) return mid;
        else l = mid + 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  }

  int search(vector<int> &nums, int target) {
    if (nums.empty()) return 0;
    auto i = low_bound(nums, target);
    if (i == -1) return 0;
    return up_bound(nums, target) - i + 1;
  }
};

#endif //CPP_053_1__SOLUTION3_H_
