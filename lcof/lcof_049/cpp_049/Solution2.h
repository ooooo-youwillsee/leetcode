//
// Created by ooooo on 2020/4/6.
//
#ifndef CPP_049__SOLUTION2_H_
#define CPP_049__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 把已经排好序的丑数 分别 *2，*3，*5，取最小的数，添加进数组中
 */
class Solution {
 public:

  int findMinValue(int count, vector<int> &nums, int num) {
    for (int i = 0; i < count; ++i) {
      if (nums[i] * num > nums[count - 1]) return nums[i] * num;
    }
    return -1;
  }

  int nthUglyNumber(int n) {
    vector<int> nums(n, 1);
    int count = 1;
    while (count < n) {
      int min_v = min({
                          findMinValue(count, nums, 2),
                          findMinValue(count, nums, 3),
                          findMinValue(count, nums, 5)});
      nums[count++] = min_v;
    }
    return nums[n - 1];
  }
};

#endif //CPP_049__SOLUTION2_H_
