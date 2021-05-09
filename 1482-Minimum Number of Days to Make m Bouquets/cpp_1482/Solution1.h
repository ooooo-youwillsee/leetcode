/**
 * @author ooooo
 * @date 2021/5/9 17:35 
 */

#ifndef CPP_1482__SOLUTION1_H_
#define CPP_1482__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	bool check(vector<int> &bloomDay, int m, int k, int target) {
		int cnt = 0, cur_cnt = 0;
		for (int i = 0; i < bloomDay.size(); i++) {
			if (bloomDay[i] <= target) {
				cur_cnt++;
			}
			if (bloomDay[i] > target) {
				cnt += cur_cnt / k;
				cur_cnt = 0;
			}
		}
		cnt += cur_cnt / k;
		return cnt >= m;
	}
	int minDays(vector<int> &bloomDay, int m, int k) {
		if (bloomDay.size() < m * k) return -1;
		int l = bloomDay[0], r = bloomDay[0];
		for (auto b: bloomDay) {
			l = min(l, b);
			r = max(r, b);
		}
		int ans = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(bloomDay, m, k, mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return ans;
	}
};

#endif //CPP_1482__SOLUTION1_H_
