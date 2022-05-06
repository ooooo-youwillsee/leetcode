//
// Created by ooooo on 2020/2/12.
//
#ifndef CPP_0055__SOLUTION2_H_
#define CPP_0055__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 贪心
 */
class Solution {
 public:
  bool canJump(vector<int> &nums) {
    int lastPos = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      // 当前的位置 i ,加上步长 nums[i]
      if (i + nums[i] >= lastPos) {
        lastPos = i;
      }
    }
    return lastPos == 0;
  }
};

#endif //CPP_0055__SOLUTION2_H_
