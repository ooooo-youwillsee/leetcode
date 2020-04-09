//
// Created by ooooo on 2020/4/9.
//
#ifndef CPP_053_1__SOLUTION1_H_
#define CPP_053_1__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int count = 0;
    for (auto &num: nums) {
      if (num == target) count++;
      else if (num > target) break;
    }
    return count;
  }
};

#endif //CPP_053_1__SOLUTION1_H_
