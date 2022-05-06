//
// Created by ooooo on 2020/4/19.
//
#ifndef CPP_059_1__SOLUTION2_H_
#define CPP_059_1__SOLUTION2_H_

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
 public:

  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (k == 0 && nums.empty()) return {};
    vector<int> ans;
    deque<int> q;
    for (int i = 0, len = nums.size(); i < len; ++i) {
      while (!q.empty() && q.front() <= i - k) q.pop_front();
      while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
      q.push_back(i);
      if (i >= k - 1) ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};

#endif //CPP_059_1__SOLUTION2_H_
