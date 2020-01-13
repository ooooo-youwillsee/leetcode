//
// Created by ooooo on 2020/1/13.
//
#ifndef CPP_0645__SOLUTION1_H_
#define CPP_0645__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
 public:
  vector<int> findErrorNums(vector<int> &nums) {
    unordered_set<int> s;
    int i = 0, sum = 0;
    for (auto &num: nums) {
      if (s.count(num)) {
        // i 为重复值
        i = num;
      } else s.insert(num);
      sum += num;
    }
    int j = (1 + nums.size()) * nums.size() / 2 + i - sum;
    return {i, j};
  }
};

#endif //CPP_0645__SOLUTION1_H_
