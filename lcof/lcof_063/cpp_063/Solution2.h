//
// Created by ooooo on 2020/4/24.
//
#ifndef CPP_063__SOLUTION2_H_
#define CPP_063__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) return 0;
    int n = prices.size(), ans = 0, min = prices[0];
    for (int i = 1; i < n; ++i) {
      if (prices[i] < min) min = prices[i];
      ans = max(ans, prices[i] - min);
    }
    return ans;
  }
};

#endif //CPP_063__SOLUTION2_H_
