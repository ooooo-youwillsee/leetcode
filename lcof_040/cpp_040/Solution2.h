//
// Created by ooooo on 2020/3/25.
//
#ifndef CPP_040__SOLUTION2_H_
#define CPP_040__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (k == 0) return {};
    sort(arr.begin(), arr.end());
    return vector<int>(arr.begin(), arr.begin() + k);
  }
};

#endif //CPP_040__SOLUTION2_H_
