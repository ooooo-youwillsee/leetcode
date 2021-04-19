/**
 * @author ooooo
 * @date 2021/4/19 09:37 
 */

#ifndef CPP_1824__SOLUTION1_H_
#define CPP_1824__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
 public:
	int minSideJumps(vector<int> nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(4, n * 3 + 1));
		dp[0][1] = dp[0][3] = 1;
		dp[0][2] = 0;
		for (int i = 1; i < n; i++) {
			if (nums[i] == 2) {
				dp[i][1] = min(dp[i - 1][1], 1 + dp[i - 1][3]);
				dp[i][3] = min(dp[i - 1][1] + 1, dp[i - 1][3]);
			} else if (nums[i] == 1) {
				dp[i][2] = min(dp[i - 1][2], 1 + dp[i - 1][3]);
				dp[i][3] = min(dp[i - 1][2] + 1, dp[i - 1][3]);
			} else if (nums[i] == 3) {
				dp[i][1] = min(dp[i - 1][1], 1 + dp[i - 1][2]);
				dp[i][2] = min(dp[i - 1][1] + 1, dp[i - 1][2]);
			} else if (nums[i] == 0) {
				dp[i][1] = min(min(dp[i - 1][1], dp[i - 1][2] + 1), dp[i - 1][3] + 1);
				dp[i][2] = min(min(dp[i - 1][2], dp[i - 1][1] + 1), dp[i - 1][3] + 1);
				dp[i][3] = min(min(dp[i - 1][3], dp[i - 1][1] + 1), dp[i - 1][2] + 1);
			}
			dp[i][nums[i]] = n * 3 + 1;
		}
		return min(min(dp[n - 1][1], dp[n - 1][2]), dp[n - 1][3]);
	}

};

#endif //CPP_1824__SOLUTION1_H_
