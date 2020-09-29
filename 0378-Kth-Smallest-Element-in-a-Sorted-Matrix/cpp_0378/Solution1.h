/**
 * @author ooooo
 * @date 2020/9/29 16:44 
 */

#ifndef CPP_0378__SOLUTION1_H_
#define CPP_0378__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int kthSmallest(vector<vector<int>> &matrix, int k) {
		int row = matrix.size(), col = matrix[0].size();
		vector<int> vec(row * col, 0);
		for (int i = 0, p = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				vec[p++] = matrix[i][j];
			}
		}
		sort(vec.begin(), vec.end());
		return vec[k - 1];
	}
};

#endif //CPP_0378__SOLUTION1_H_
