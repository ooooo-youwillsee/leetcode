/**
 * @author ooooo
 * @date 2021/4/14 20:21 
 */

#ifndef CPP_1760__SOLUTION1_H_
#define CPP_1760__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	int minimumSize(vector<int> &nums, int maxOperations) {
		int l = 1, r = *max_element(nums.begin(), nums.end());
		int ans = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			int cnt = 0;
			for (int i = 0; i < nums.size(); i++) {
				// 如果nums[i] % mid = 0, 比如9%3=0， 只要分两次就可以了
				cnt += (nums[i] - 1) / mid;
			}
			if (cnt <= maxOperations) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return ans;
	}
};

#endif //CPP_1760__SOLUTION1_H_
