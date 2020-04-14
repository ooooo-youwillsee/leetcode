//
// Created by ooooo on 2020/4/14.
//
#ifndef CPP_056_1__SOLUTION1_H_
#define CPP_056_1__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int findFirstBit(int num) {
    int ans = 1;
    while ((ans & num) == 0) {
      ans <<= 1;
    }
    return ans;
  }

  vector<int> singleNumbers(vector<int> &nums) {
    int num = 0;
    for (auto &n : nums) num ^= n;
    num = findFirstBit(num);
    int a = 0, b = 0;
    for (auto &n :nums) {
      if ((num & n) == 0) a ^= n;
      else b^= n;
    }
    return {a, b};
  }
};

#endif //CPP_056_1__SOLUTION1_H_
