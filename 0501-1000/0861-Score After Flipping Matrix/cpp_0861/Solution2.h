/**
 * @author ooooo
 * @date 2020/12/7 16:07 
 */

#ifndef CPP_0861__SOLUTION2_H_
#define CPP_0861__SOLUTION2_H_

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
 public:
	int matrixScore(vector<vector<int>> &A) {
		int m = A.size(), n = A[0].size();
		int ans = m * (1 << (n - 1));
		vector<int> cols(n, 0);
		for (int j = 1; j < n; ++j) {
			for (int i = 0; i < m; ++i) {
				if (A[i][0] == 0) {
					// need flip
					cols[j] += 1 - A[i][j];
				} else {
					cols[j] += A[i][j];
				}
			}
			int k = max(cols[j], m - cols[j]);
			ans += k * (1 << (n - j - 1));
		}
		return ans;
	}
};

#endif //CPP_0861__SOLUTION2_H_
