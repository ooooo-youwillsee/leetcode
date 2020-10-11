/**
 * @author ooooo
 * @date 2020/10/11 20:13 
 */

#ifndef CPP_0073__SOLUTION2_H_
#define CPP_0073__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

// 用第一行和第一列存储
class Solution {
 public:
	void setZeroes(vector<vector<int>> &matrix) {
		if (matrix.empty()) return;
		int m = matrix.size(), n = matrix[0].size();
		bool first_row_0 = false, first_col_0 = false;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					if (i == 0) {
						first_row_0 = true;
					}
					if (j == 0) {
						first_col_0 = true;
					}
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[0][j] == 0 || matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		for (int i = 0; first_col_0 && i < m; ++i) {
			matrix[i][0] = 0;
		}
		for (int i = 0; first_row_0 && i < n; ++i) {
			matrix[0][i] = 0;
		}
	}
};

#endif //CPP_0073__SOLUTION2_H_
