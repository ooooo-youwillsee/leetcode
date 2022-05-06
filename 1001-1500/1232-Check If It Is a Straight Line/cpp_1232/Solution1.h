/**
 * @author ooooo
 * @date 2021/1/17 12:19 
 */

#ifndef CPP_1232__SOLUTION1_H_
#define CPP_1232__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool checkStraightLine(vector<vector<int>> &coordinates) {
		sort(coordinates.begin(), coordinates.end(), [](const vector<int> &x, const vector<int> &y) {
			return x[0] < y[0];
		});

		for (int i = 2; i < coordinates.size(); ++i) {
			int x1 = coordinates[i - 2][0], y1 = coordinates[i - 2][1];
			int x2 = coordinates[i - 1][0], y2 = coordinates[i - 1][1];
			int x3 = coordinates[i][0], y3 = coordinates[i][1];
			if ((y2 - y1) * (x3 - x2) != (x2 - x1) * (y3 - y2)) {
				return false;
			}
		}
		return true;
	}
};

#endif //CPP_1232__SOLUTION1_H_
