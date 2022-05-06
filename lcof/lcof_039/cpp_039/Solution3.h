//
// Created by ooooo on 2020/3/24.
//
#ifndef CPP_039__SOLUTION3_H_
#define CPP_039__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 *
 */
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    int num = nums[0];
    int count = 1;
    for (int i = 1, len = nums.size(); i < len; ++i) {
      if (count == 0) {
        num = nums[i];
        count = 1;
      } else if (nums[i] == num) {
        count += 1;
      } else {
        count--;
      }
    }
    return num;
  }
};

#endif //CPP_039__SOLUTION3_H_
