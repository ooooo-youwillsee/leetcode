//
// Created by ooooo on 2020/2/24.
//
#ifndef CPP_0300__SOLUTION1_H_
#define CPP_0300__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i] =  num[j] < num[i]  ==> max( dp[i] , dp[j] + 1 )
 */
class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    if (n <= 1) return n;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
      }
    }
    return ans;
  }
};

#endif //CPP_0300__SOLUTION1_H_
