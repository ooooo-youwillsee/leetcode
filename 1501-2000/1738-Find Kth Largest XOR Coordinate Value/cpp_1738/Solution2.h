/**
 * @author ooooo
 * @date 2021/5/19 21:11 
 */

#ifndef CPP_1738__SOLUTION2_H_
#define CPP_1738__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int kthLargestValue(vector<vector<int>> &matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		vector<int> ans;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				dp[i + 1][j + 1] = dp[i + 1][j] ^ dp[i][j + 1] ^ dp[i][j] ^ matrix[i][j];
				ans.push_back(dp[i + 1][j + 1]);
			}
		}
		sort(ans.begin(), ans.end());
		return ans[ans.size() - k];
	}
};
#endif //CPP_1738__SOLUTION2_H_
