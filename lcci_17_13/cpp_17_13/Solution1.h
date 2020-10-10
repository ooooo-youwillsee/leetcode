/**
 * @author ooooo
 * @date 2020/10/10 11:58 
 */

#ifndef CPP_17_13__SOLUTION1_H_
#define CPP_17_13__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	int respace(vector<string> &dictionary, string sentence) {
		int n = sentence.size();
		if (dictionary.empty()) return n;
		int min_len = dictionary[0].size(), max_len = 0;
		unordered_set<string> word_set;
		for (auto &item: dictionary) {
			int len = item.size();
			min_len = min(min_len, len);
			max_len = max(max_len, len);
			word_set.insert(item);
		}

		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n; i++) {
			dp[i + 1] = dp[i] + 1;
			if (i + 1 < min_len) continue;

			for (int j = min_len; j <= max_len; j++) {
				int prev_i = i - j + 1;
				if (prev_i < 0) continue;
				string s = sentence.substr(prev_i, j);
				if (word_set.find(s) != word_set.end()) {
					dp[i + 1] = min(dp[i + 1], dp[prev_i]);
				}
			}
		}
		return dp[n];
	}
};

#endif //CPP_17_13__SOLUTION1_H_
