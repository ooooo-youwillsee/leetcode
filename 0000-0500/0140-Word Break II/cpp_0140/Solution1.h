/**
 * @author ooooo
 * @date 2020/11/1 10:24 
 */

#ifndef CPP_0140__SOLUTION1_H_
#define CPP_0140__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	int min_len = INT_MAX, max_len = INT_MIN;
	unordered_set<string> set;

	vector<string> dfs(string &s, int i) {
		vector<string> ans;
		if (i >= s.size()) {
			ans.push_back("");
			return ans;
		}

		for (int j = min_len; j <= max_len; ++j) {
			if (i + j > s.size()) continue;
			string word = s.substr(i, j);
			if (set.count(word)) {
				vector<string> sentences = dfs(s, i + j);
				for (auto sentence: sentences) {
					ans.push_back(sentence == "" ? word + sentence : word + " " + sentence);
				}
			}
		}
		return ans;
	}

	bool exist(string s) {
		vector<bool> dp(s.length() + 1, false);
		// 0 表示空字符串
		dp[0] = true;
		for (int i = 1; i <= s.length(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[j] && set.count(s.substr(j, i - j))) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.length()];
	}

	vector<string> wordBreak(string s, vector<string> &wordDict) {
		for (int i = 0; i < wordDict.size(); ++i) {
			min_len = min(min_len, (int) wordDict[i].size());
			max_len = max(max_len, (int) wordDict[i].size());
			set.insert(wordDict[i]);
		}
		if (!exist(s)) return {};
		return dfs(s, 0);
	}
};

#endif //CPP_0140__SOLUTION1_H_
