//
// Created by ooooo on 2020/4/16.
//
#ifndef CPP_057_2__SOLUTION1_H_
#define CPP_057_2__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  vector<int> group(int l, int r) {
    vector<int> ans;
    for (; l < r; l++) {
      if (l != 0) ans.push_back(l);
    }
    return ans;
  }

  vector<vector<int>> findContinuousSequence(int target) {
    int l = 0, r = 0, sum = 0, end = (target + 1) / 2;
    vector<vector<int>> ans;
    while (l <= end) {
      if (sum < target) {
        sum += r++;
      } else if (sum == target) {
        ans.push_back(group(l, r));
        sum += r++;
      } else {
        sum -= l++;
      }
    }
    return ans;
  }
};

#endif //CPP_057_2__SOLUTION1_H_
