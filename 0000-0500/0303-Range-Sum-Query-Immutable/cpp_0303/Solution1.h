//
// Created by ooooo on 2020/1/29.
//
#ifndef CPP_0303__SOLUTION1_H_
#define CPP_0303__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
 public:
  int *sum;
  NumArray(vector<int> &nums) {
    sum = new int[nums.size() + 1];
    sum[0] = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum[i + 1] = sum[i] + nums[i];
    }
  }

  int sumRange(int i, int j) {
    return sum[j + 1] - sum[i];
  }

};

#endif //CPP_0303__SOLUTION1_H_
