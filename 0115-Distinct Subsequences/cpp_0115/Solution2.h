/**
 * @author ooooo
 * @date 2021/3/17 19:18 
 */

#ifndef CPP_0115__SOLUTION2_H_
#define CPP_0115__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
 public:

	int numDistinct(string s, string t) {
		int m = s.size(), n = t.size();
		vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
		for (int i = 0; i <= m; ++i) {
			dp[i][0] = 1;
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i < j) {
					continue;
				}
				if (s[i] == t[j]) {
					dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
				} else {
					dp[i + 1][j + 1] = dp[i][j + 1];
				}
			}
		}
		return dp[m][n];
	}
};

#endif //CPP_0115__SOLUTION2_H_
