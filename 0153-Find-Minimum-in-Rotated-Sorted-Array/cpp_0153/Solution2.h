/**
 * @author ooooo
 * @date 2020/9/25 23:55 
 */

#ifndef CPP_0153__SOLUTION2_H_
#define CPP_0153__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	int findMin(vector<int> &nums, int l, int r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] > nums[l] && nums[mid] > nums[r]) return findMin(nums, mid + 1, r);
		if (nums[mid] < nums[r] && nums[mid] > nums[l]) return findMin(nums, l, mid);
		return *min_element(nums.begin() + l, nums.begin() + r + 1);
	}

	int findMin(vector<int> &nums) {
		if (nums[0] <= nums[nums.size() - 1]) return nums[0];
		return findMin(nums, 0, nums.size() - 1);
	}
};

#endif //CPP_0153__SOLUTION2_H_
