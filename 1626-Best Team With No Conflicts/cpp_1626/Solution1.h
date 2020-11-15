/**
 * @author ooooo
 * @date 2020/11/15 09:03 
 */

#ifndef CPP_1626__SOLUTION1_H_
#define CPP_1626__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

/**
 * dp[i] 表示有第i个球员的最大得分
 */
class Solution {
 public:
	int bestTeamScore(vector<int> &scores, vector<int> &ages) {
		int n = scores.size();
		vector<pair<int, int >> p;
		for (int i = 0; i < n; ++i) {
			p.push_back(make_pair(ages[i], scores[i]));
		}
		sort(p.begin(), p.end());
		vector<int> dp(n);
		dp[0] = p[0].second;
		int ans = dp[0];
		for (int i = 1; i < p.size(); ++i) {
			int age = p[i].first, score = p[i].second;
			dp[i] = score;
			// 尝试每一个人和i组成球队
			for (int j = 0; j < i; ++j) {
				int prev_age = p[j].first, prev_score = p[j].second;
				if (!(prev_age < age && prev_score > score)) {
					// 无矛盾的，可以组队
					dp[i] = max(dp[j] + score, dp[i]);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

#endif //CPP_1626__SOLUTION1_H_
