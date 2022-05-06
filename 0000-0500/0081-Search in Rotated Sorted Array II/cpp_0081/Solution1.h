/**
 * @author ooooo
 * @date 2021/4/7 10:16 
 */

#ifndef CPP_0081__SOLUTION1_H_
#define CPP_0081__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	bool search(vector<int> &nums, int target) {
		int n = nums.size();
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] < nums[r]) {
				if (target >= nums[mid] && target <= nums[r]) {
					auto it = lower_bound(nums.begin() + mid, nums.begin() + r + 1, target);
					return it != nums.end() && *it == target;
				} else {
					r = mid;
				}
			} else if (nums[mid] > nums[l]) {
				if (target >= nums[l] && target <= nums[mid]) {
					auto it = lower_bound(nums.begin() + l, nums.begin() + mid + 1, target);
					return it != nums.end() && *it == target;
				} else {
					l = mid;
				}
			} else {
				while (l <= r) {
					if (nums[l] == target) {
						return true;
					}
					l++;
				}
			}
		}
		return false;
	}
};

#endif //CPP_0081__SOLUTION1_H_
