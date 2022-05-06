/**
 * @author ooooo
 * @date 2020/10/5 11:28 
 */

#ifndef CPP_0516__SOLUTION1_H_
#define CPP_0516__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		int ans = 1;
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				} else {
					dp[i][j] = max(dp[i + 1][j - 1], max(dp[i][j - 1], dp[i + 1][j]));
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};

#endif //CPP_0516__SOLUTION1_H_
