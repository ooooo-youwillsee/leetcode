/**
 * @author ooooo
 * @date 2020/10/4 21:18 
 */

#ifndef CPP_1312__SOLUTION1_H_
#define CPP_1312__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int minInsertions(string s) {
		int n = s.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1];
				} else {
					dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
		return dp[0][n - 1];
	}
};

#endif //CPP_1312__SOLUTION1_H_
