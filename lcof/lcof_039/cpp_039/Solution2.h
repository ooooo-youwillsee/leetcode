//
// Created by ooooo on 2020/3/24.
//
#ifndef CPP_039__SOLUTION2_H_
#define CPP_039__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * partition  timeout
 */
class Solution {
 public:

  int partition(int i, int j, vector<int> &nums) {
    int k = i, item = nums[i];
    for (int p = i + 1; p <= j; p++) {
      if (nums[p] <= item) swap(nums[++k], nums[p]);
    }
    swap(nums[k], nums[i]);
    return k;;
  }

  int majorityElement(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    auto k = partition(start, end, nums);
    int mid = nums.size() / 2;
    while (k != mid) {
      if (k < mid) {
        start = k + 1;
        k = partition(start, end, nums);
      } else {
        end = k - 1;
        k = partition(start, end, nums);
      }
    }
    return nums[k];
  }
};

#endif //CPP_039__SOLUTION2_H_
