//
// Created by ooooo on 2020/4/25.
//
#ifndef CPP_066__SOLUTION1_H_
#define CPP_066__SOLUTION1_H_

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> constructArr(vector<int> &a) {
    vector<int> ans(a.size(), 0);
    int num = 1;
    for (int i = 0; i < a.size(); ++i) {
      ans[i] = num;
      num *= a[i];
    }
    num = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
      ans[i] *= num;
      num *= a[i];
    }
    return ans;
  }
};

#endif //CPP_066__SOLUTION1_H_
