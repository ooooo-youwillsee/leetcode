//
// Created by ooooo on 2020/4/10.
//
#ifndef CPP_053_2__SOLUTION3_H_
#define CPP_053_2__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * binary
 */
class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == mid) {
        l = mid + 1;
      } else {
        if (mid == 0 || nums[mid - 1] == mid - 1) {
          return mid;
        }
        r = mid - 1;
      }
    }
    return nums.size();
  }
};

#endif //CPP_053_2__SOLUTION3_H_
