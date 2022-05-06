/**
 * @author ooooo
 * @date 2020/11/23 20:23 
 */

#ifndef CPP_0452__SOLUTION1_H_
#define CPP_0452__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int findMinArrowShots(vector<vector<int>> &points) {
		if (points.empty()) return 0;
		sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
			return u[1] < v[1];
		});
		int ans = 1, cur_pos = points[0][1];
		for (int i = 1; i < points.size(); ++i) {
			int start = points[i][0], end = points[i][1];
			if (cur_pos <= end && cur_pos >= start) {
				continue;
			}
			ans++;
			cur_pos = end;
		}
		return ans;
	}
};

#endif //CPP_0452__SOLUTION1_H_
