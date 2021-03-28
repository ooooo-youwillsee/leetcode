/**
 * @author ooooo
 * @date 2021/3/28 12:13 
 */

#ifndef CPP_1792__SOLUTION1_H_
#define CPP_1792__SOLUTION1_H_

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

	double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
		// 按照通过率排序
		auto diff = [&](const int i) {
			double x = (double) classes[i][0], y = (double) classes[i][1];
			return (x + 1) / (y + 1) - x / y;
		};
		priority_queue<pair<double, int>> pq;

		int n = classes.size();
		for (int i = 0; i < n; ++i) {
			pq.emplace(diff(i), i);
		}

		while (extraStudents) {
			int x = pq.top().second;
			pq.pop();
			classes[x][0]++;
			classes[x][1]++;
			extraStudents--;
			pq.emplace(diff(x), x);
		}

		double ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += (classes[i][0]) * 1.0 / classes[i][1];
		}

		return ans / n;
	}
};

#endif //CPP_1792__SOLUTION1_H_
