/**
 * @author ooooo
 * @date 2021/3/7 08:31 
 */

#ifndef CPP_0131__SOLUTION2_H_
#define CPP_0131__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	void dfs(string &s, int i, vector<string> &row) {
		if (i == s.size()) {
			ans.push_back(row);
			return;
		}

		for (int len = 1; len <= s.size() - i; ++len) {
			if (dp[i][i + len - 1]) {
				row.push_back(s.substr(i, len));
				dfs(s, i + len, row);
				row.pop_back();
			}
		}
	}
	vector<vector<bool>> dp;
	vector<vector<string>> ans;
	vector<vector<string>> partition(string s) {
		// 动态规划判断回文串
		int n = s.size();
		dp.assign(n, vector<bool>(n));
		for (int i = 0; i < n; ++i) {
			dp[i][i] = true;
		}
		for (int i = n - 2; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				if (j - i > 1) {
					dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
				} else {
					dp[i][j] = s[i] == s[j];
				}
			}
		}
		vector<string> row;
		dfs(s, 0, row);
		return ans;
	}
};

#endif //CPP_0131__SOLUTION2_H_
