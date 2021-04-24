/**
 * @author ooooo
 * @date 2021/4/24 11:13 
 */

#ifndef CPP_0377__SOLUTION2_H_
#define CPP_0377__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int combinationSum4(vector<int> &nums, int target) {
		int n = nums.size();
		vector<int> dp(target + 1);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (int j = 0; j < n; j++) {
				if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
					dp[i] += dp[i - nums[j]];
				}
			}
		}
		return dp[target];
	}
};

#endif //CPP_0377__SOLUTION2_H_
