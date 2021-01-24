/**
 * @author ooooo
 * @date 2021/1/24 17:15 
 */

#ifndef CPP_1706__SOLUTION1_H_
#define CPP_1706__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution {
 public:

	vector<int> findBall(vector<vector<int>> &g) {
		int m = g.size(), n = g[0].size();
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			int row = 0, col = i;
			while (row < m) {
				if ((col + 1 < n && g[row][col] == 1 && g[row][col + 1] == 1)) {
					col++;
				} else if ((col - 1 >= 0 && g[row][col] == -1 && g[row][col - 1] == -1)) {
					col--;
				} else {
					col = -1;
					break;
				}
				row++;
			}
			ans.push_back(col);
		}
		return ans;
	}

};

#endif //CPP_1706__SOLUTION1_H_
