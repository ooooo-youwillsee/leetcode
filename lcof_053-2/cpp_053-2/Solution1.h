//
// Created by ooooo on 2020/4/10.
//
#ifndef CPP_053_2__SOLUTION1_H_
#define CPP_053_2__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    vector<bool> marked(nums.size() + 1, false);
    for (auto &num : nums) marked[num] = true;
    for (int i = 0, len = marked.size(); i < len; ++i) {
      if (!marked[i]) return i;
    }
    return -1;
  }
};

#endif //CPP_053_2__SOLUTION1_H_
