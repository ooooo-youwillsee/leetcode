/**
 * @author ooooo
 * @date 2021/3/2 09:03 
 */

#ifndef CPP_0304__SOLUTION1_H_
#define CPP_0304__SOLUTION1_H_

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
		preSum.assign(m, vector<int>(n + 1, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				preSum[i][j + 1] = preSum[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (preSum.empty()) {
			return 0;
		}
		int sum = 0;
		for (int i = row1; i <= row2; ++i) {
			sum += preSum[i][col2 + 1] - preSum[i][col1];
		}
		return sum;
	}
};

#endif //CPP_0304__SOLUTION1_H_
