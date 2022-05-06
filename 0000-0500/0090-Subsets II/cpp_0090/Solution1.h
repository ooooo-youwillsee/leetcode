/**
 * @author ooooo
 * @date 2021/3/31 09:58 
 */

#ifndef CPP_0090__SOLUTION1_H_
#define CPP_0090__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<vector<int>> ans;

	void dfs(vector<int> &nums, int i, vector<int> &tmp) {
		ans.push_back(tmp);
		for (int j = i; j < nums.size(); j++) {
			if (j > i && nums[j] == nums[j - 1]) continue;
			tmp.push_back(nums[j]);
			dfs(nums, j + 1, tmp);
			tmp.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<int> tmp = {};
		dfs(nums, 0, tmp);
		return ans;
	}
};

#endif //CPP_0090__SOLUTION1_H_
