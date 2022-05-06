/**
 * @author ooooo
 * @date 2021/4/17 09:59 
 */

#ifndef CPP_0220__SOLUTION1_H_
#define CPP_0220__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
	bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
		if (nums.size() < 2) return false;
		int n = nums.size();
		multiset<long long> set;

		for (int i = 0; i < n; i++) {
			auto it = set.lower_bound((long long) nums[i] - (long long) t);
			if (it != set.end() && *it <= (long long) nums[i] + (long long) t) {
				return true;
			}
			set.insert(nums[i]);
			if (set.size() > k) {
				set.erase(set.find(nums[i - k]));
			}
		}
		return false;
	}
};

#endif //CPP_0220__SOLUTION1_H_
