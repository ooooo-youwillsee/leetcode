//
// Created by ooooo on 2020/4/17.
//
#ifndef CPP_056_2__SOLUTION1_H_
#define CPP_056_2__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * hash
 */
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    unordered_map<int, int> m;
    for (auto &num: nums) m[num]++;
    for (auto[k, v] :m) {
      if (v == 1) return k;
    }
    return -1;
  }
};

#endif //CPP_056_2__SOLUTION1_H_
