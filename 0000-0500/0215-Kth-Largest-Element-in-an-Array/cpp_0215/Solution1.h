//
// Created by ooooo on 2020/2/20.
//
#ifndef CPP_0215__SOLUTION1_H_
#define CPP_0215__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * sort
 */
class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
  }
};

#endif //CPP_0215__SOLUTION1_H_
