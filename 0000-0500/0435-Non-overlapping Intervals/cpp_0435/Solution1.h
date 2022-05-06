/**
 * @author ooooo
 * @date 2020/12/31 15:00 
 */

#ifndef CPP_0435__SOLUTION1_H_
#define CPP_0435__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals) {
		if (intervals.size() <= 1) return 0;
		sort(intervals.begin(), intervals.end(), [](const auto &x, const auto &y) {
			return x[1] < y[1];
		});

		int n = intervals.size();
		int ans = 1;
		int right = intervals[0][1];
		for (int i = 1; i < n; ++i) {
			if (intervals[i][0] >= right) {
				ans++;
				right = intervals[i][1];
			}
		}
		return n - ans;
	}
};

#endif //CPP_0435__SOLUTION1_H_
