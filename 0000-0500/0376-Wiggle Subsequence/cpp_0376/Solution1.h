/**
 * @author ooooo
 * @date 2020/12/12 11:31 
 */

#ifndef CPP_0376__SOLUTION1_H_
#define CPP_0376__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int wiggleMaxLength(vector<int> &nums) {
		int n = nums.size();
		if (n <= 1) return n;
		vector<int> dp(n, 1);
		for (int i = 1; i < n; ++i) {
			dp[i] = nums[i] - nums[0] != 0 ? 2 : 1;
			for (int k = 1; k < i; ++k) {
				int diff = nums[i] - nums[k];
				int prevDiff = nums[k] - nums[k - 1];
				if ((diff < 0 && prevDiff > 0) || (diff > 0 && prevDiff < 0)) {
					dp[i] = max(dp[i], dp[k] + 1);
				}
			}
		}
		return dp[n - 1];
	}
};

#endif //CPP_0376__SOLUTION1_H_
