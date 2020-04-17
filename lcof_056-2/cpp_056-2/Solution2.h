//
// Created by ooooo on 2020/4/17.
//
#ifndef CPP_056_2__SOLUTION2_H_
#define CPP_056_2__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int singleNumber(vector<int> &nums) {
    vector<int> bits(32, 0);
    for (auto &num: nums) {
      unsigned int bit_1 = 1;
      for (int j = 31; j >= 0; --j) {
        if (num & bit_1) bits[j]++;
        bit_1 <<= 1;
      }
    }

    int ans = 0;
    for (auto &bit :bits) {
      ans = (ans << 1) + bit % 3;
    }
    return ans;
  }
};

#endif //CPP_056_2__SOLUTION2_H_
