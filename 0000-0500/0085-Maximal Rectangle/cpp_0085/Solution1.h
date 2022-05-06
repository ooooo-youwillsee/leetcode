/**
 * @author ooooo
 * @date 2020/12/26 11:24 
 */

#ifndef CPP_0085__SOLUTION1_H_
#define CPP_0085__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maximalRectangle(vector<vector<char>> &matrix) {
		if (matrix.empty()) return 0;
		// 先计算每个点左边的宽度
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> width(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j == 0) {
					width[i][j] = matrix[i][j] == '1';
					continue;
				}
				if (matrix[i][j] == '1') {
					width[i][j] = width[i][j - 1] + 1;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0') {
					continue;
				}
				// 向上计算最小宽度
				int min_width = INT_MAX;
				for (int k = i; k >= 0; --k) {
					min_width = min(min_width, width[k][j]);
					ans = max(ans, min_width * (i - k + 1));
				}
			}
		}
		return ans;
	}
};

#endif //CPP_0085__SOLUTION1_H_
