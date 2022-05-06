/**
 * @author ooooo
 * @date 2020/11/26 16:28 
 */

#ifndef CPP_0164__SOLUTION1_H_
#define CPP_0164__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maximumGap(vector<int> &nums) {
		if (nums.size() < 2) return 0;
		sort(nums.begin(), nums.end());
		int diff = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			diff = max(diff, nums[i + 1] - nums[i]);
		}
		return diff;
	}
};

#endif //CPP_0164__SOLUTION1_H_
