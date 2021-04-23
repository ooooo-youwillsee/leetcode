/**
 * @author ooooo
 * @date 2021/4/23 19:52 
 */

#ifndef CPP_0368__SOLUTION1_H_
#define CPP_0368__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<int> largestDivisibleSubset(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> dp(n, 1);
		int max_cnt = 1;
		int max_value = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (nums[i] % nums[j] == 0) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (dp[i] > max_cnt) {
				max_cnt = dp[i];
				max_value = nums[i];
			}
		}

		vector<int> ans;
		if (max_cnt == 1) {
			return {nums[0]};
		}
		for (int i = n - 1; i >= 0; i--) {
			if (dp[i] == max_cnt && max_value % nums[i] == 0) {
				ans.push_back(nums[i]);
				max_cnt--;
				max_value = nums[i];
			}
		}
		return ans;
	}
};

#endif //CPP_0368__SOLUTION1_H_
