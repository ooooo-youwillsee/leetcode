//
// Created by ooooo on 2020/2/12.
//
#ifndef CPP_0055__SOLUTION3_H_
#define CPP_0055__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 贪心
 */
class Solution {
 public:
  bool canJump(vector<int> &nums) {
    // k 表示能跳的最远距离
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > k) return false;
      k = max(k, i + nums[i]);
    }
    return true;
  }
};

#endif //CPP_0055__SOLUTION3_H_
