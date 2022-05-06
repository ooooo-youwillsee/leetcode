/**
 * @author ooooo
 * @date 2020/12/7 15:01 
 */

#ifndef CPP_0861__SOLUTION1_H_
#define CPP_0861__SOLUTION1_H_

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
 * 判断左上角是否为1， 如果为0,可以flipX或者flipY， 后面的行只能flipX
 */
class Solution {
 public:

	vector<vector<int>> A;
	int m, n;

	int calcMax(vector<int> &first_cols, vector<int> &rows, vector<int> &cols) {
		int ans = 0;
		for (int i = 1; i < m; ++i) {
			if (first_cols[i] == 0) {
				flipX(i, 0, rows, cols);
			}
		}
		ans += m * (int) pow(2, n - 1);
		for (int j = 1; j < n; ++j) {
			int k = max(cols[j], m - cols[j]);
			ans += k * (int) pow(2, n -j - 1);
		}
		return ans;
	}

	void flipX(int i, int j, vector<int> &rows, vector<int> &cols) {
		rows[i] = n - rows[i];
		for (int k = 0; k < n; ++k) {
			cols[k] = A[i][k] == 1 ? cols[k] - 1 : cols[k] + 1;
		}
	}

	void flipY(int i, int j, vector<int> &rows, vector<int> &cols) {
		cols[j] = m - cols[j];
		for (int k = 0; k < m; ++k) {
			rows[k] = A[k][j] == 1 ? rows[k] - 1 : rows[k] + 1;
		}
	}

	int matrixScore(vector<vector<int>> &A) {
		this->m = A.size();
		this->n = A[0].size();
		this->A = A;
		vector<int> rows, cols;
		rows.assign(m, 0);
		cols.assign(n, 0);
		vector<int> first_cols(m, 0);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (A[i][j] == 1) {
					rows[i]++;
					cols[j]++;
				}
				if (j == 0) {
					first_cols[i] = A[i][j];
				}
			}
		}
		int ans = 0;

		if (A[0][0] == 0) {
			// flipX
			vector<int> new_rows1 = rows, new_cols1 = cols;
			first_cols[0] = !first_cols[0];
			flipX(0, 0, new_rows1, new_cols1);
			ans = max(ans, calcMax(first_cols, new_rows1, new_cols1));
			first_cols[0] = !first_cols[0];

			// flipY
			for (int i = 0; i < m; ++i) {
				first_cols[i] = !first_cols[i];
			}
			vector<int> new_rows2 = rows, new_cols2 = cols;
			flipY(0, 0, new_rows2, new_cols2);
			ans = max(ans, calcMax(first_cols, new_rows2, new_cols2));
		} else {
			ans = max(ans, calcMax(first_cols, rows, cols));
		}
		return ans;
	}
};

#endif //CPP_0861__SOLUTION1_H_
