//
// Created by ooooo on 2020/2/6.
//
#ifndef CPP_0448__SOLUTION2_H_
#define CPP_0448__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int new_index = abs(nums[i]) - 1;
      if (nums[new_index] > 0) {
        nums[new_index] *= -1;
      }
    }
    vector<int> ans;
    for (int i = 1; i <= nums.size(); ++i) {
      if (nums[i - 1] > 0) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

#endif //CPP_0448__SOLUTION2_H_
