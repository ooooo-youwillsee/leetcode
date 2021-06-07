//
// Created by ooooo on 2020/3/3.
//
#ifndef CPP_0494__SOLUTION2_H_
#define CPP_0494__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]
 *
 * 背包问题
 *
 */
class Solution {
 public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int n = nums.size();
		int sum = accumulate(nums.begin(), nums.end(),  0);
		if (target > sum) return 0;
		int dp[n+1][2*sum+1];
		memset(dp, 0, sizeof(dp));
		dp[0][sum] = 1; // 组成0的有一种方式
		// 0 -> sum-1 负数
		// sum+1 -> 2*sum +1 正数
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2*sum+1; j++) {
				if (j - nums[i] >= 0) {
					dp[i+1][j]+= dp[i][j - nums[i]];
				}
				if (j + nums[i] < 2*sum +1) {
					dp[i+1][j]+= dp[i][j + nums[i]];
				}
			}
		}
		return dp[n][sum + target];
	}
};
#endif //CPP_0494__SOLUTION2_H_
