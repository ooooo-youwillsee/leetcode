/**
 * @author ooooo
 * @date 2020/10/24 11:55 
 */

#ifndef CPP_1024__SOLUTION2_H_
#define CPP_1024__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i] 表示0到i区间的最小数目
 */
class Solution {
 public:
	int videoStitching(vector<vector<int>> &clips, int T) {
		vector<int> dp(T + 1);
		for (int i = 1; i <= T; ++i) {
			dp[i] = clips.size() + 1;
			for (auto &clip : clips) {
				if (clip[0] < i && i <= clip[1]) {
					dp[i] = min(dp[i], dp[clip[0]] + 1);
				}
			}
			//cout << "finally i:" << i << " ->" << dp[i] << " " << endl;
		}
		return dp[T] > clips.size() ? -1 : dp[T];
	}
};

#endif //CPP_1024__SOLUTION2_H_
