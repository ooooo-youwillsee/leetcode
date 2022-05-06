/**
 * @author ooooo
 * @date 2020/10/11 20:09 
 */

#ifndef CPP_0073__SOLUTION1_H_
#define CPP_0073__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	void setZeroes(vector<vector<int>> &matrix) {
		if (matrix.empty()) return;
		int m = matrix.size(), n = matrix[0].size();
		vector<bool> rows(m), cols(n);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					rows[i] = true;
					cols[j] = true;
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (rows[i] || cols[j]) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

#endif //CPP_0073__SOLUTION1_H_
