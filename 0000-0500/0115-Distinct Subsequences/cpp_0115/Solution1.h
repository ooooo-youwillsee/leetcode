/**
 * @author ooooo
 * @date 2021/3/17 18:04 
 */

#ifndef CPP_0115__SOLUTION1_H_
#define CPP_0115__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
 public:

	// dp[i][j] 表示以s中j位置结尾的子序列个数
	int numDistinct(string s, string t) {
		int m = s.size(), n = t.size();
		vector<vector<long long>> dp(n, vector<long long>(m, 0));
		for (int i = 0; i < m; ++i) {
			if (s[i] == t[0]) {
				// 第一个字符结尾的
				dp[0][i] = 1;
			}
		}
		for (int i = 1; i < n; ++i) {
			// 向后查找有dp[i - 1][j]的子序列个数
			for (int j = 0; j < m; ++j) {
				if (dp[i - 1][j] > 0) {
					// 大于0,说明有
					for (int k = j + 1; k < m; ++k) {
						if (s[k] == t[i]) {
							dp[i][k] += dp[i - 1][j];
						}
					}
				}
			}
		}
		return accumulate(dp[n - 1].begin(), dp[n - 1].end(), (long long) 0);
	}
};

#endif //CPP_0115__SOLUTION1_H_
