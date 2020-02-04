//
// Created by ooooo on 2020/2/4.
//
#ifndef CPP_0053__SOLUTION1_H_
#define CPP_0053__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i] 表示数组长度为i的最大连续数组
 * dp[i] = nums[i] (dp[i-1] < 0)
 * dp[i] = dp[i-1] + nums[i] (dp[i-1] >= 0)  前一个大于0，有增益效果，所有加上
 *
 */
class Solution {
 public:

  int maxSubArray(vector<int> &nums) {
    int ans = nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (dp[i - 1] < 0) {
        dp[i] = nums[i];
      } else {
        dp[i] = dp[i - 1] + nums[i];
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }

  int maxSubArray2(vector<int> &nums) {
    int ans = nums[0], sum = 0;
    for (auto &num: nums) {
      if (sum > 0) {
        sum += num;
      } else {
        sum = num;
      }
      ans = max(sum, ans);
    }
    return ans;
  }
};

#endif //CPP_0053__SOLUTION1_H_
