/**
 * @author ooooo
 * @date 2021/2/28 13:14 
 */

#ifndef CPP_1738__SOLUTION1_H_
#define CPP_1738__SOLUTION1_H_


#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <numeric>

using namespace std;

class Solution {

 public:

	int kthLargestValue(vector<vector<int>> &matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		vector<int> ans;
		vector<vector<int>> up(m + 1, vector<int>(n + 1)), dp(m + 1, vector<int>(n + 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0) {
					up[i + 1][j + 1] = matrix[i][j];
				} else {
					up[i + 1][j + 1] = matrix[i][j] ^ up[i][j + 1];
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i + 1][j + 1] = dp[i + 1][j] ^ up[i][j + 1] ^ matrix[i][j];
				ans.push_back(dp[i + 1][j + 1]);
			}
		}
		sort(ans.begin(), ans.end());
		return ans[ans.size() - k];
	}

};
#endif //CPP_1738__SOLUTION1_H_
