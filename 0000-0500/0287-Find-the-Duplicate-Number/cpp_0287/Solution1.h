//
// Created by ooooo on 2020/2/23.
//
#ifndef CPP_0287__SOLUTION1_H_
#define CPP_0287__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * hash
 */
class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    unordered_set<int> set;
    for (auto &num : nums) {
      if (set.count(num)) {
        return num;
      }
      set.insert(num);
    }
    return -1;
  }
};

#endif //CPP_0287__SOLUTION1_H_
