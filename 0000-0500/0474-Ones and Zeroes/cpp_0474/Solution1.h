/**
 * @author ooooo
 * @date 2021/6/6 10:23 
 */

#ifndef CPP_0474__SOLUTION1_H_
#define CPP_0474__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int findMaxForm(vector<string> &strs, int m, int n) {
		int k = strs.size();
		int dp[k + 1][m + 1][n + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < k; i++) {
			int cnt0 = 0, cnt1 = 0;
			for (auto c: strs[i]) {
				if (c == '0') cnt0++;
				else cnt1++;
			}
			for (int j = 0; j <= m; j++) {
				for (int p = 0; p <= n; p++) {
					dp[i + 1][j][p] = dp[i][j][p];
					if (j >= cnt0 && p >= cnt1) {
						dp[i + 1][j][p] = max(dp[i + 1][j][p], 1 + dp[i][j - cnt0][p - cnt1]);
					}
				}
			}
		}
		return dp[k][m][n];
	}
};

#endif //CPP_0474__SOLUTION1_H_
