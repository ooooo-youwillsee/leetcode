/**
 * @author ooooo
 * @date 2021/3/8 12:05 
 */

#ifndef CPP_0132__SOLUTION1_H_
#define CPP_0132__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int minCut(string s) {
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, 0));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				if (i == j) {
					dp[i][j] = true;
				} else if (j == i + 1) {
					dp[i][j] = s[i] == s[j];
				} else {
					dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
				}
			}
		}

		vector<int> cnt(n, n);
		for (int i = 0; i < n; ++i) {
			if (dp[0][i]) {
				cnt[i] = 0;
				continue;
			}
			for (int k = i; k >= 0; --k) {
				if (dp[k][i]) {
					cnt[i] = min(cnt[i], cnt[k - 1] + 1);
				}
			}
		}
		return cnt[n - 1];
	}
};

#endif //CPP_0132__SOLUTION1_H_
