/**
 * @author ooooo
 * @date 2020/10/4 22:20 
 */

#ifndef CPP_0005__SOLUTION1_H_
#define CPP_0005__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		int l = 0, r = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = i + 1 >= j - 1 || dp[i + 1][j - 1];
					if (dp[i][j] && j - i > r - l) {
						l = i;
						r = j;
					}
				}
			}
		}
		return s.substr(l, r - l + 1);
	}
};

#endif //CPP_0005__SOLUTION1_H_
