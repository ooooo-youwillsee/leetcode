/**
 * @author ooooo
 * @date 2021/1/9 12:23 
 */

#ifndef CPP_0123__SOLUTION1_H_
#define CPP_0123__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][j][k]
 */
class Solution {
 public:
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		int k = 2;
		int v = -100001;
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));
		for (int i = 1; i <= k; ++i) {
			dp[0][i][0] = dp[0][i][1] = v;
		}
		dp[0][0][1] = v;

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int p = prices[i];
			for (int j = 1; j <= k; ++j) {
				dp[i + 1][j][1] = max(dp[i][j - 1][0] - p, dp[i][j][1]);
				dp[i + 1][j][0] = max(dp[i][j][1] + p, dp[i][j][0]);
				ans = max(ans, dp[i + 1][j][0]);
			}
		}
		return ans;
	}
};

#endif //CPP_0123__SOLUTION1_H_
