/**
 * @author ooooo
 * @date 2021/1/24 17:10 
 */

#ifndef CPP_1727__SOLUTION1_H_
#define CPP_1727__SOLUTION1_H_


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
 public:

	int largestSubmatrix(vector<vector<int>> &matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		// 计算每一个方块，向上的直连的个数
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0) {
					dp[i][j] = matrix[i][j];
					continue;
				}
				if (matrix[i][j] == 1) {
					dp[i][j] = 1 + dp[i - 1][j];
				}
			}
		}

		int ans = 0;
		// 从最后一层开始向上
		for (int i = m - 1; i >= 0; --i) {
			// 先形成矩阵数组
			vector<int> row;
			for (int j = 0; j < n; ++j) {
				if (dp[i][j]) {
					row.push_back(dp[i][j]);
				}
			}
			// 最大的放在前面
			sort(row.begin(), row.end(), greater<int>());
			// 计算每一层的最大矩形个数
			int curMinHeight = INT_MAX;
			for (int j = 0; j < row.size(); ++j) {
				curMinHeight = min(curMinHeight, row[j]);
				ans = max(ans, curMinHeight * (j + 1));
			}
		}
		return ans;
	}
};

#endif //CPP_1727__SOLUTION1_H_
