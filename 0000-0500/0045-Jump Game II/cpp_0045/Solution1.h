/**
 * @author ooooo
 * @date 2021/6/4 20:16 
 */

#ifndef CPP_0045__SOLUTION1_H_
#define CPP_0045__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 暴力dp
 */
class Solution {
 public:
	int jump(vector<int> &nums) {
		int n = (int) nums.size();
		vector<int> dp(n, n);
		dp[0] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (i - j <= nums[j]) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[n - 1];
	}
};
#endif //CPP_0045__SOLUTION1_H_
