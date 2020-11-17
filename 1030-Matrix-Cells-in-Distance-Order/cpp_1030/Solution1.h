/**
 * @author ooooo
 * @date 2020/11/17 17:35 
 */

#ifndef CPP_1030__SOLUTION1_H_
#define CPP_1030__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * sort
 */
class Solution {
 public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> ans;
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				ans.push_back({r, c});
			}
		}
		sort(ans.begin(), ans.end(), [&](vector<int> x, vector<int> y) {
			int p1 = abs(x[0] - r0) + abs(x[1] - c0);
			int p2 = abs(y[0] - r0) + abs(y[1] - c0);
			return p1 < p2;
		});
		return ans;
	}
};

#endif //CPP_1030__SOLUTION1_H_
