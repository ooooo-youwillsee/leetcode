/**
 * @author ooooo
 * @date 2020/12/19 19:06 
 */

#ifndef CPP_0714__SOLUTION1_H_
#define CPP_0714__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maxProfit(vector<int> &prices, int fee) {
		int n = prices.size();
		vector<vector<int>> dp(n + 1, vector<int>(2));
		dp[0][1] = -50000;
		for (int i = 0; i < n; ++i) {
			int p = prices[i];
			dp[i + 1][0] = max(dp[i][0], dp[i][1] + p - fee);
			dp[i + 1][1] = max(dp[i][1], dp[i][0] - p);
		}
		return dp[n][0];
	}
};

#endif //CPP_0714__SOLUTION1_H_
