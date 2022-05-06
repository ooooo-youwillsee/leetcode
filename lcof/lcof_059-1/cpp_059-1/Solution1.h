//
// Created by ooooo on 2020/4/19.
//
#ifndef CPP_059_1__SOLUTION1_H_
#define CPP_059_1__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (k == 0 && nums.empty()) return {};
    vector<int> ans;
    int max_v = *max_element(nums.begin(), nums.begin() + k);
    ans.push_back(max_v);
    for (int i = k, size = nums.size(); i < size; ++i) {
      if (nums[i] > max_v) {
        max_v = nums[i];
      } else if (nums[i - k] == max_v) {
        max_v = *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1);
      }
      ans.push_back(max_v);
    }
    return ans;
  }
};

#endif //CPP_059_1__SOLUTION1_H_
