//
// Created by ooooo on 2020/3/9.
//
#ifndef CPP_011__SOLUTION1_H_
#define CPP_011__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * O(n)
 */
class Solution {
 public:
  int minArray(vector<int> &numbers) {
    for (int i = 0, len = numbers.size() - 1; i < len; ++i) {
      if (numbers[i] > numbers[i + 1]) return numbers[i + 1];
    }
    return numbers[0];
  }
};

#endif //CPP_011__SOLUTION1_H_
