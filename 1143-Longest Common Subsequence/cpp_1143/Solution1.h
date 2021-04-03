/**
 * @author ooooo
 * @date 2021/4/3 12:12 
 */

#ifndef CPP_1143__SOLUTION1_H_
#define CPP_1143__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int longestCommonSubsequence(string s1, string s2) {
		int m = s1.size(), n = s2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (s1[i] == s2[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				} else {
					dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}
		return dp[m][n];
	}
};

#endif //CPP_1143__SOLUTION1_H_
