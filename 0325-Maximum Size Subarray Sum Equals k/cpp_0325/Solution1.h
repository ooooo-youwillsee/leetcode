/**
 * @author ooooo
 * @date 2021/6/4 20:52 
 */

#ifndef CPP_0325__SOLUTION1_H_
#define CPP_0325__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
 public:
	int maxSubArrayLen(vector<int> &nums, int k) {
		int n = nums.size();
		unordered_map<int, int> m;
		m[0] = -1;
		int ans = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			if (m.find(sum - k) != m.end()) {
				ans = max(ans, i - m[sum - k]);
			}
			if (m.find(sum) == m.end()) {
				m[sum] = i;
			}
		}
		return ans;
	}
};
#endif //CPP_0325__SOLUTION1_H_
