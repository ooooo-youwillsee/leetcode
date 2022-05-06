//
// Created by ooooo on 2020/3/5.
//
#ifndef CPP_003__SOLUTION1_H_
#define CPP_003__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * hash
 */
class Solution {
 public:
  int findRepeatNumber(vector<int> &nums) {
    unordered_set<int> set;
    for (auto &num: nums) {
      if (set.count(num)) {
        return num;
      }
      set.insert(num);
    }
    return -1;
  }
};

#endif //CPP_003__SOLUTION1_H_
