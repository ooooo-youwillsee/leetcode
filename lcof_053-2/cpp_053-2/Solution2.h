//
// Created by ooooo on 2020/4/10.
//
#ifndef CPP_053_2__SOLUTION2_H_
#define CPP_053_2__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
      if (i != nums[i]) return i;
    }
    return len;
  }
};

#endif //CPP_053_2__SOLUTION2_H_
