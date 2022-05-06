/**
 * @author ooooo
 * @date 2021/3/7 07:55 
 */

#ifndef CPP_0131__SOLUTION1_H_
#define CPP_0131__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<vector<string>> dfs(string &s, int i) {
		if (i == s.size()) return {};
		vector<vector<string>> ans;
		for (int len = 1; len <= s.size() - i; ++len) {
			if (dp[i][i + len - 1]) {
				vector<vector<string>> res = dfs(s, i + len);
				if (res.empty()) {
					ans.push_back({s.substr(i, i + len)});
				}
				for (auto &row : res) {
					ans.push_back({s.substr(i, len)});
					ans.back().insert(ans.back().end(), row.begin(), row.end());
				}
			}
		}
		return ans;
	}

	vector<vector<bool>> dp;
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
		return dfs(s, 0);
	}
};

#endif //CPP_0131__SOLUTION1_H_
