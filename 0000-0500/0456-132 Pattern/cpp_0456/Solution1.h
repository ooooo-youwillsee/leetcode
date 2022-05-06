/**
 * @author ooooo
 * @date 2021/3/24 16:32 
 */

#ifndef CPP_0456__SOLUTION1_H_
#define CPP_0456__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// o(nlogn)
class Solution {
 public:
	bool find132pattern(vector<int> &nums) {
		int n = nums.size();
		if (n < 3) {
			return false;
		}
		int left_value = nums[0];
		multiset<int> rights;
		for (int i = 2; i < n; ++i) {
			rights.insert(nums[i]);
		}

		for (int i = 1; i < n - 1; ++i) {
			if (left_value < nums[i]) {
				auto it = rights.upper_bound(left_value);
				if (it != rights.end() && *it < nums[i]) {
					return true;
				}
			}
			left_value = min(left_value, nums[i]);
			rights.erase(rights.find(nums[i + 1]));
		}
		return false;
	}
};

#endif //CPP_0456__SOLUTION1_H_
