//
// Created by ooooo on 2020/1/13.
//
#ifndef CPP_0645__SOLUTION2_H_
#define CPP_0645__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int> &nums) {
    unordered_map<int, int> m;
    for (auto &num: nums) {
      m[num]++;
    }
    int i = -1, j = -1;
    for (int k = 1; k <= nums.size(); ++k) {
      // k = 0 为缺失数字
      if (m[k] == 0) j = k;
      // k = 2 为重复数字
      else if (m[k] == 2) i = k;
    }
    return {i, j};
  }
};

#endif //CPP_0645__SOLUTION2_H_
