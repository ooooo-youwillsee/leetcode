/**
 * @author ooooo
 * @date 2021/3/9 17:55 
 */

#ifndef CPP_1546__SOLUTION2_H_
#define CPP_1546__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
	int maxNonOverlapping(vector<int> &nums, int target) {
		int n = nums.size();
		int sum = 0;
		int ans = 0;
		// 刚开始前缀和为0
		unordered_set<int> set = {0};
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			if (set.count(sum - target)) {
				ans++;
				set.clear();
			}
			set.insert(sum);
		}

		return ans;
	}
};
#endif //CPP_1546__SOLUTION2_H_
