//
// Created by ooooo on 2020/2/4.
//
#ifndef CPP_0121__SOLUTION1_H_
#define CPP_0121__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 找到最小值
 */
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int ans = 0, min_price = INT_MAX;
    for (auto price: prices) {
      if (price < min_price) {
        min_price = price;
      } else {
        ans = max(price - min_price, ans);
      }
    }
    return ans;
  }

};

#endif //CPP_0121__SOLUTION1_H_
