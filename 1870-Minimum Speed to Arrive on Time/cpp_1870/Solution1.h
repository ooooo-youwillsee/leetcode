/**
 * @author ooooo
 * @date 2021/5/25 22:22 
 */

#ifndef CPP_1870__SOLUTION1_H_
#define CPP_1870__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
	int minSpeedOnTime(vector<int> &dist, double hour) {
		if (dist.size() - 1 >= hour) return -1;
		int l = 1, r = *max_element(dist.begin(), dist.end()) * 100;
		int ans = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			double sum = 0;
			for (int i = 0; i < dist.size() - 1; i++) {
				int d = dist[i];
				int v = d % mid == 0 ? d / mid : d / mid + 1;
				sum += v;
			}
			sum += dist[dist.size() - 1] * 1.0 / mid;

			if (sum <= hour) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return ans;

	};

#endif //CPP_1870__SOLUTION1_H_
