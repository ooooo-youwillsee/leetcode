//
// Created by ooooo on 2020/4/6.
//
#ifndef CPP_049__SOLUTION3_H_
#define CPP_049__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp
 */
class Solution {
 public:

  int nthUglyNumber(int n) {
    vector<int> nums(n, 1);
    int count = 1, num_2 = 0, num_3 = 0, num_5 = 0;
    while (count < n) {
      int min_v = min({nums[num_2] * 2, nums[num_3] * 3, nums[num_5] * 5});
      nums[count] = min_v;
      // 可能会出现 3 * 2 = 6 和 2 * 3 = 6
      if (nums[num_2] * 2 == nums[count]) num_2++;
      if (nums[num_3] * 3 == nums[count]) num_3++;
      if (nums[num_5] * 5 == nums[count]) num_5++;
      count++;
    }
    return nums[n - 1];
  }
};

#endif //CPP_049__SOLUTION3_H_
