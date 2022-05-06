/**
 * @author ooooo
 * @date 2020/11/9 09:12 
 */

#ifndef CPP_0973__SOLUTION2_H_
#define CPP_0973__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * sort
 */
class Solution {
 public:

	vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
		sort(points.begin(), points.end(), [](auto x, auto y) {
			return x[0] * x[0] + x[1] * x[1] < y[0] * y[0] + y[1] * y[1];
		});

		return {points.begin(), points.begin() + K};
	}
};

#endif //CPP_0973__SOLUTION2_H_
