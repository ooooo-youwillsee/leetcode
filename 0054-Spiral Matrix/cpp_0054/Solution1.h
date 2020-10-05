/**
 * @author ooooo
 * @date 2020/10/5 17:16 
 */

#ifndef CPP_0054__SOLUTION1_H_
#define CPP_0054__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/*
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
*/
class Solution {
 public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		if (matrix.empty()) return {};
		int m = matrix.size(), n = matrix[0].size();
		vector<int> ans;
		int size = m * n;
		for (int c = 0; c < m / 2 + 1; c++) {
			for (int i = 0 + c; i < n - 1 - c && size > 0; i++) {
				ans.push_back(matrix[c][i]);
				size--;
			}
			for (int i = 0 + c; i < m - 1 - c && size > 0; i++) {
				ans.push_back(matrix[i][n - 1 - c]);
				size--;
			}
			for (int i = 0 + c; i < n - 1 - c && size > 0; i++) {
				ans.push_back(matrix[m - 1 - c][n - 1 - i]);
				size--;
			}
			for (int i = 0 + c; i < m - 1 - c && size > 0; i++) {
				ans.push_back(matrix[m - 1 - i][c]);
				size--;
			}
		}
		if (size) ans.push_back(matrix[m / 2][n / 2]);
		return ans;
	}
};

#endif //CPP_0054__SOLUTION1_H_
