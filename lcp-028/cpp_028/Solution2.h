/**
 * @author ooooo
 * @date 2021/4/10 20:28 
 */

#ifndef CPP_028__SOLUTION2_H_
#define CPP_028__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

int purchasePlans(vector<int> nums, int target) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int mod = 1e9 + 7;
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		auto it = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
		long cnt = 0;
		if (it != nums.end() && *it == target - nums[i]) {
			cnt = it - (nums.begin() + i);
		} else if (it == nums.end()) {
			int j = n - 1;
			for (; j > i; --j) {
				if (nums[j] + nums[i] <= target) {
					break;
				}
			}
			cnt = j - i;
		} else if (it != nums.end()) {
			cnt = (it - 1) - (nums.begin() + i);
		}
		ans = (ans + cnt) % mod;
	}
	return ans;
}

#endif //CPP_028__SOLUTION2_H_
