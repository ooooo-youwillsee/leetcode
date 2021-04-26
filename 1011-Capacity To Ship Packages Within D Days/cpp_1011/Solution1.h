/**
 * @author ooooo
 * @date 2021/4/26 19:42 
 */

#ifndef CPP_1011__SOLUTION1_H_
#define CPP_1011__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:

	bool check(vector<int> &weights, int k, int D) {
		int d = 0;
		int cur = 0;
		for (int i = 0; i < weights.size(); i++) {
			if (weights[i] > k) return false;
			if (cur + weights[i] > k) {
				d++;
				cur = 0;
			}
			cur += weights[i];
		}
		d++;
		return d <= D;
	}

	int shipWithinDays(vector<int> &weights, int D) {
		int l = 0;
		int r = 0;
		int n = weights.size();
		for (int i = 0; i < n; i++) {
			r += weights[i];
			l = max(l, weights[i]);
		}
		int ans = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(weights, mid, D)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return ans;
	}
};
#endif //CPP_1011__SOLUTION1_H_
