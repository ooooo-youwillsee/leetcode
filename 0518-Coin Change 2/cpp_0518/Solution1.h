/**
 * @author ooooo
 * @date 2021/2/17 19:21 
 */

#ifndef CPP_0518__SOLUTION1_H_
#define CPP_0518__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int change(int amount, vector<int> &coins) {
		int n = coins.size();
		vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; ++i) {
			dp[0][i] = 1;
		}
		dp[0][0] = 1;
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < n; ++j) {
				int coin = coins[j], cnt = 0;
				while (i - cnt * coin >= 0) {
					dp[i][j + 1] += dp[i - cnt * coin][j];
					cnt++;
				}
			}
		}
		return dp[amount][n];
	}
};

#endif //CPP_0518__SOLUTION1_H_
