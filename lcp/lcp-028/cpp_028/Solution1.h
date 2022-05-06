/**
 * @author ooooo
 * @date 2021/4/10 20:27 
 */

#ifndef CPP_028__SOLUTION1_H_
#define CPP_028__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int purchasePlans(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int l = 0, r = n - 1;
		long long ans = 0;
		while (l < r) {
			if (nums[l] + nums[r] > target) r--;
			else {
				ans += r - l;
				l++;
			}
		}
		return ans % 1000000007;
	}
};

#endif //CPP_028__SOLUTION1_H_
