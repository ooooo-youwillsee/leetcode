//
// Created by ooooo on 2020/4/9.
//
#ifndef CPP_053_1__SOLUTION2_H_
#define CPP_053_1__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int low_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (nums[mid] == target) {
        r = mid;
      } else if (nums[mid] < target) {
        l = mid;
      }
    }
    return nums[l] == target ? l : -1;
  }

  int up_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return nums[l] == target ? l : -1;
  }

  int search(vector<int> &nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end()) return 0;
    return upper_bound(nums.begin(), nums.end(), target) - it;
  }
};

#endif //CPP_053_1__SOLUTION2_H_
