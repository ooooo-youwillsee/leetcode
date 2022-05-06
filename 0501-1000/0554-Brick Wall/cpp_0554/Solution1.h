/**
 * @author ooooo
 * @date 2021/5/2 08:14 
 */

#ifndef CPP_0554__SOLUTION1_H_
#define CPP_0554__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int leastBricks(vector<vector<int>> &wall) {
		unordered_map<int, int> m;
		for (int i = 0; i < wall.size(); i++) {
			vector<int> w = wall[i];
			int preSum = 0;
			for (int j = 0; j < w.size() - 1; j++) {
				preSum += w[j];
				m[preSum]++;
			}
		}

		int maxCol = 0;
		for (auto &e: m) {
			maxCol = max(maxCol, e.second);
		}

		return wall.size() - maxCol;
	}
};
#endif //CPP_0554__SOLUTION1_H_
