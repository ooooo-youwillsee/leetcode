/**
 * @author ooooo
 * @date 2021/3/4 12:09 
 */

#ifndef CPP_0354__SOLUTION1_H_
#define CPP_0354__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maxEnvelopes(vector<vector<int>> &envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](const auto &x, const auto &y) {
			return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
		});

		int n = envelopes.size();
		vector<int> dp(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			dp[i] = 1;
			for (int j = i - 1; j >= 0; --j) {
				if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

#endif //CPP_0354__SOLUTION1_H_
