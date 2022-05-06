/**
 * @author ooooo
 * @date 2020/9/18 09:18 
 */

#ifndef CPP_0047__SOLUTION1_H_
#define CPP_0047__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	void permuteUnique(vector<int> nums, int i) {
		if (i == nums.size() - 1) {
			ans.push_back(nums);
			return;
		}
		for (int j = i; j < nums.size(); ++j) {
			if (j != i && nums[j] == nums[i]) continue;
			swap(nums[i], nums[j]);
			permuteUnique(nums, i + 1);
		}
	}

	vector<vector<int>> ans;

	vector<vector<int>> permuteUnique(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		permuteUnique(nums, 0);
		return ans;
	}
};

#endif //CPP_0047__SOLUTION1_H_
