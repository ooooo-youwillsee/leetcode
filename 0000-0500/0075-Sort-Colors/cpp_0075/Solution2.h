//
// Created by ooooo on 2020/2/14.
//
#ifndef CPP_0075__SOLUTION2_H_
#define CPP_0075__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 双指针
 */
class Solution {
 public:

  void sortColors(vector<int> &nums) {
    if (nums.size() <= 1) return;
    int i = 0, j = nums.size() - 1, k = 0;
    while (k <= j) {
      if (nums[k] == 0) {
        swap(nums[i++], nums[k++]);
      } else if (nums[k] == 1) {
        k++;
      } else {
        swap(nums[j--], nums[k]);
      }
    }
  }
};

#endif //CPP_0075__SOLUTION2_H_
