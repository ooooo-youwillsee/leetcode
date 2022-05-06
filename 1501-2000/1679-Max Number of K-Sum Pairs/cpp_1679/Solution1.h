/**
 * @author ooooo
 * @date 2021/1/29 20:45 
 */

#ifndef CPP_1679__SOLUTION1_H_
#define CPP_1679__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maxOperations(vector<int> &nums, int k) {
		sort(nums.begin(), nums.end());
		int l = 0, r = nums.size() - 1;
		int ans = 0;
		while (l < r) {
			int sum = nums[l] + nums[r];
			if (sum == k) {
				ans++;
				l++;
				r--;
			} else if (sum < k) {
				l++;
			} else {
				r--;
			}
		}
		return ans;
	}
};

#endif //CPP_1679__SOLUTION1_H_
