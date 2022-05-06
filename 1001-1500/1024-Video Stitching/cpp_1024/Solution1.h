/**
 * @author ooooo
 * @date 2020/10/24 09:55 
 */

#ifndef CPP_1024__SOLUTION1_H_
#define CPP_1024__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][j] 表示i到j区间的最小数目
 */
class Solution {
 public:
	int videoStitching(vector<vector<int>> &clips, int T) {
		vector<vector<int>> dp(T + 1, vector<int>(T + 1));

		for (int i = T - 1; i >= 0; --i) {
			for (int j = i + 1; j <= T; ++j) {
				dp[i][j] = clips.size() + 1;
				for (int k = 0; k < clips.size(); ++k) {
					int l = clips[k][0], r = clips[k][1];
					if (r <= i || j <= l) continue;
					if (l <= i && j <= r) {
						dp[i][j] = 1;
					} else if (r <= j) {
						// 以最优解去计算
						dp[i][j] = min(dp[i][j], dp[i][r] + dp[r][j]);
					} else {
						// 以最优解去计算
						dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j]);
					}
					//cout << "i:" << i << " j:" << j << " ->" << dp[i][j] << " " << endl;
				}
				cout << "finally i:" << i << " j:" << j << " ->" << dp[i][j] << " " << endl;
			}
		}

		return dp[0][T] > clips.size() ? -1 : dp[0][T];
	}
};

#endif //CPP_1024__SOLUTION1_H_
