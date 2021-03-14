/**
 * @author ooooo
 * @date 2021/3/14 14:53 
 */

#ifndef CPP_1779__SOLUTION1_H_
#define CPP_1779__SOLUTION1_H_


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
		unordered_map<int, vector<int>> m;
		int minDiff = INT_MAX;
		for (int i = 0; i < points.size(); ++i) {
			if (points[i][0] == x || points[i][1] == y) {
				int diff = abs(points[i][0] - x) + abs(points[i][1] - y);
				minDiff = min(minDiff, diff);
				m[diff].push_back(i);
			}
		}

		if (minDiff == INT_MAX) {
			return -1;
		}
		return m[minDiff][0];
	}
};

#endif //CPP_1779__SOLUTION1_H_
