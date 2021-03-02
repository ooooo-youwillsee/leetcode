/**
 * @author ooooo
 * @date 2021/3/2 16:41 
 */

#ifndef CPP_0304__SOLUTION2_H_
#define CPP_0304__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
 public:

	vector<vector<int>> preSum;
	NumMatrix(vector<vector<int>> &matrix) {
		if (matrix.empty()) {
			return;
		}
		int m = matrix.size(), n = matrix[0].size();
		preSum.assign(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (preSum.empty()) {
			return 0;
		}
		return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
	}
};

#endif //CPP_0304__SOLUTION2_H_
