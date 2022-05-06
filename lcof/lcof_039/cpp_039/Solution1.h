//
// Created by ooooo on 2020/3/24.
//
#ifndef CPP_039__SOLUTION1_H_
#define CPP_039__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * hash
 */
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> num_map;
    int n = nums.size() / 2;
    for (auto &num: nums) {
      num_map[num]++;
      if (num_map[num] > n) return num;
    }
    return -1;
  }
};

#endif //CPP_039__SOLUTION1_H_
