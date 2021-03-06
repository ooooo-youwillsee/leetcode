/**
 * @author ooooo
 * @date 2021/3/6 16:27 
 */

#ifndef CPP_1642__SOLUTION2_H_
#define CPP_1642__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * 二分法
 */
class Solution {
 public:
	int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
		int n = heights.size();
		int l = 0, r = n - 1;
		vector<int> diff(n - 1);
		for (int i = 0; i < n - 1; ++i) {
			diff[i] = max(heights[i + 1] - heights[i], 0);
		}
		int pos = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(mid, diff, bricks, ladders)) {
				pos = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return pos;
	}

	bool check(int mid, vector<int> &diff, int bricks, int ladders) {
		vector<int> nums = {diff.begin(), diff.begin() + mid};
		sort(nums.begin(), nums.end(), greater<int>());
		int need = 0;
		for (int i = ladders; i < nums.size() ; ++i) {
			need += nums[i];
		}
		return need <= bricks;
	}
};

#endif //CPP_1642__SOLUTION2_H_
