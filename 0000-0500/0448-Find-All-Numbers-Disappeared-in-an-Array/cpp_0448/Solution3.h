//
// Created by ooooo on 2020/2/6.
//
#ifndef CPP_0448__SOLUTION3_H_
#define CPP_0448__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 从第一个数字开始，逐一置为-1
 */
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (num == -1) continue;
      while (true) {
        int j = nums[num - 1];
        if (j != -1) {
          nums[num - 1] = -1;
          num = j;
        } else {
          break;
        }
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

#endif //CPP_0448__SOLUTION3_H_
