/**
 * @author ooooo
 * @date 2021/4/15 14:11 
 */

#ifndef CPP_0213__SOLUTION1_H_
#define CPP_0213__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	int rob(vector<int> &nums, int l, int r) {
		vector<vector<int>> dp(r - l + 2, vector<int>(2));
		dp[0][1] = -1000;
		for (int i = l; i <= r; i++) {
			dp[i - l + 1][0] = max(dp[i - l][1], dp[i - l][0]);
			dp[i - l + 1][1] = max(dp[i - l][0] + nums[i], dp[i - l][1]);
		}
		return dp[r - l + 1][1];
	}

	int rob(vector<int> &nums) {
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return max(nums[0], nums[1]);
		int n = nums.size();
		int ans = max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
		return ans;
	}
};

#endif //CPP_0213__SOLUTION1_H_
