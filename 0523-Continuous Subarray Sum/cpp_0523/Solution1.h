//
// Created by ooooo on 6/2/2021.
//

#ifndef CPP_0523_SOLUTION1_H
#define CPP_0523_SOLUTION1_H

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    if (n < 2) return false;
    int preSum = nums[0];
    unordered_set<int> s;
    s.insert(0);
    for (int i = 1; i < n; i++) {
      preSum += nums[i];
      if (s.count(preSum % k)) {
        return true;
      }
      s.insert((preSum - nums[i]) % k);
    }

    return false;
  }
}

#endif//CPP_0523_SOLUTION1_H
