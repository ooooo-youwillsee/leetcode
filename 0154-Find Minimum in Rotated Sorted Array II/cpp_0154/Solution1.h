/**
 * @author ooooo
 * @date 2021/4/9 13:08 
 */

#ifndef CPP_0154__SOLUTION1_H_
#define CPP_0154__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int findMin(vector<int> &nums) {
		int n = nums.size();
		int l = 0, r = n - 1;
		if (nums[l] < nums[r]) return nums[l];
		int ans = nums[l];
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[l] < nums[mid]) {
				ans = min(ans, nums[l]);
				l = mid + 1;
			} else if (nums[mid] < nums[r]) {
				ans = min(ans, nums[mid]);
				r = mid - 1;
			} else {
				while (l <= r) {
					ans = min(ans, nums[l++]);
				}
			}
		}
		return ans;
	}
};

#endif //CPP_0154__SOLUTION1_H_
