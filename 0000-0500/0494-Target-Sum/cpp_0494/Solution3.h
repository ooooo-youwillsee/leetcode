/**
 * @author ooooo
 * @date 2020/10/6 23:07 
 */

#ifndef CPP_0494__SOLUTION3_H_
#define CPP_0494__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
	int findTargetSumWays(vector<int> &nums, int S) {
		int n = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum < S) return 0;
		vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
		dp[0][nums[0] + sum] = 1;
		dp[0][-nums[0] + sum] += 1;

		for (int i = 1; i < n; i++) {
			for (int j = -sum; j < sum + 1; j++) {
				if (j + sum - nums[i] >= 0 && j + sum - nums[i] < 2 * sum + 1) {
					dp[i][j + sum] += dp[i - 1][j + sum - nums[i]];
				}
				if (j + sum + nums[i] >= 0 && j + sum + nums[i] < 2 * sum + 1) {
					dp[i][j + sum] += dp[i - 1][j + sum + nums[i]];
				}
				//cout << " i: " << i << " j: " << j << " :" << dp[i][j + sum] << "\t";
			}
			//cout << endl;
		}
		return dp[n - 1][S + sum];
	}
};

#endif //CPP_0494__SOLUTION3_H_
