/**
 * @author ooooo
 * @date 2021/5/4 09:15 
 */

#ifndef CPP_1473__SOLUTION1_H_
#define CPP_1473__SOLUTION1_H_

#include <vector>
#include <iostream>

using namespace std;
class Solution {
 public:

	/**
	dp[m][n][target] 表示第m个房子，涂第n个颜色，为target的neighborhood的值
	*/

	int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX / 2)));


		// 没有涂色
		if (houses[0] == 0) {
			for (int j = 1; j <= n; j++) {
				dp[0][j][1] = cost[0][j - 1];
			}
		} else {
			dp[0][houses[0]][1] = 0;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= target; k++) {
					// 没有涂色
					if (houses[i] == 0) {
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][j - 1]);
						for (int p = 1; p <= n; p++) {
							if (p != j) {
								dp[i][j][k] = min(dp[i][j][k], dp[i - 1][p][k - 1] + cost[i][j - 1]);
							}
						}
					} else {
						// 当前涂的颜色必须是house[i]
						if (j != houses[i]) continue;
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
						for (int p = 1; p <= n; p++) {
							if (p != j) {
								dp[i][j][k] = min(dp[i][j][k], dp[i - 1][p][k - 1]);
							}
						}
					}
				}
			}
		}
		int ans = INT_MAX / 2;
		for (int j = 1; j <= n; j++) {
			ans = min(ans, dp[m - 1][j][target]);
		}
		return ans == INT_MAX / 2 ? -1 : ans;
	}
};

#endif //CPP_1473__SOLUTION1_H_
