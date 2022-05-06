
/**
 * @author ooooo
 * @date 2021/3/1 17:21 
 */

#ifndef CPP_1658__SOLUTION1_H_
#define CPP_1658__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
	int minOperations(vector<int> &nums, int x) {
		int target = accumulate(nums.begin(), nums.end(), 0) - x;
		int l = 0, r = 0;
		int n = nums.size();
		int ans = -1, sum = 0;
		while (r < n) {
			sum += nums[r];
			while (sum > target && l <= r) {
				sum -= nums[l];
				l++;
			}
			if (sum == target) {
				ans = max(ans, r - l + 1);
			}
			r++;
		}
		return ans == -1 ? -1 : n - ans;
	}
};

#endif //CPP_1658__SOLUTION1_H_
