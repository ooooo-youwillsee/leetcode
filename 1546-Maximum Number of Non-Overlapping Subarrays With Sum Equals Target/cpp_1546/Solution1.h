/**
 * @author ooooo
 * @date 2021/3/9 11:59 
 */

#ifndef CPP_1546__SOLUTION1_H_
#define CPP_1546__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;


// timeout
class Solution {
 public:
	int maxNonOverlapping(vector<int> &nums, int target) {
		int n = nums.size();
		vector<int> preSum(n + 1);
		for (int i = 0; i < n; ++i) {
			preSum[i + 1] = preSum[i] + nums[i];
		}

		vector<int> dp(n);
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				dp[i] = dp[i - 1];
			}
			for (int j = i; j >= 0; --j) {
				if (preSum[i + 1] - preSum[j] == target) {
					dp[i] = max(dp[i], (j > 0 ? dp[j - 1] : 0) + 1);
				}
			}
		}

		return dp[n - 1];
	}
};

#endif //CPP_1546__SOLUTION1_H_
