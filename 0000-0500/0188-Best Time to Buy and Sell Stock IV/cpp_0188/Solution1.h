/**
 * @author ooooo
 * @date 2020/12/28 16:31 
 */

#ifndef CPP_0188__SOLUTION1_H_
#define CPP_0188__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][j][n] 表示第i天进行第j次交易，持有n股
 */
class Solution {
 public:
	int maxProfit(int k, vector<int> &prices) {
		int n = prices.size();
		int ans = 0;
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
		for (int i = 1; i <= k; ++i) {
			dp[0][i][0] = -10000;
			dp[0][i][1] = -10000;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				int p = prices[i];
				dp[i + 1][j + 1][0] = max(dp[i][j + 1][0], dp[i][j + 1][1] + p);
				dp[i + 1][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][0] - p);
				ans = max(ans, dp[i + 1][j + 1][0]);
			}
		}
		return ans;
	}
};

#endif //CPP_0188__SOLUTION1_H_
