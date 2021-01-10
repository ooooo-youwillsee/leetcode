/**
 * @author ooooo
 * @date 2021/1/10 上午9:27 
 */

#ifndef CPP_0228__SOLUTION1_H_
#define CPP_0228__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<string> summaryRanges(vector<int> &nums) {
		if (nums.empty()) return {};
		int prev = 0, n = nums.size();
		vector<string> ans;
		for (int j = 1; j < n; ++j) {
			if (nums[j] == nums[j - 1] + 1) continue;
			if (prev != j - 1) {
				ans.emplace_back(to_string(nums[prev]) + "->" + to_string(nums[j - 1]));
			} else {
				ans.emplace_back(to_string(nums[prev]));
			}
			prev = j;
		}

		if (prev != n - 1) {
			ans.emplace_back(to_string(nums[prev]) + "->" + to_string(nums[n - 1]));
		} else {
			ans.emplace_back(to_string(nums[prev]));
		}

		return ans;
	}
};

#endif //CPP_0228__SOLUTION1_H_
