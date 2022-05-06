/**
 * @author ooooo
 * @date 2020/10/5 17:51 
 */

#ifndef CPP_0059__SOLUTION1_H_
#define CPP_0059__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<vector<int>> generateMatrix(int n) {
		int cur = 1, max = n * n;
		vector<vector<int>> ans(n, vector<int>(n, 0));

		for (int c = 0; c < n / 2 + 1; c++) {
			for (int i = 0 + c; i < n - 1 - c; i++) {
				ans[0 + c][i] = cur++;
			}
			for (int i = 0 + c; i < n - 1 - c; i++) {
				ans[i][n - 1 - c] = cur++;
			}
			for (int i = 0 + c; i < n - 1 - c; i++) {
				ans[n - 1 - c][n - 1 - i] = cur++;
			}
			for (int i = 0 + c; i < n - 1 - c; i++) {
				ans[n - 1 - i][0 + c] = cur++;
			}
		}
		if (cur <= max) {
			ans[n / 2][n / 2] = cur;
		}

		return ans;
	}
};
#endif //CPP_0059__SOLUTION1_H_
