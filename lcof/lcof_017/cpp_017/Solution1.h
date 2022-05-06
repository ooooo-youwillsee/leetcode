//
// Created by ooooo on 2020/3/13.
//
#ifndef CPP_017__SOLUTION1_H_
#define CPP_017__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
 public:
  vector<int> printNumbers(int n) {
    int num = 1;
    while (n--) num *= 10;
    vector<int> ans(num - 1);
    for (int i = 1; i < num; ++i) {
      ans[i-1] = i;
    }
    return ans;
  }
};

#endif //CPP_017__SOLUTION2_H_
