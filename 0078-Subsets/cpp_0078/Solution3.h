/**
 * @author ooooo
 * @date 2020/9/20 12:14 
 */

#ifndef CPP_0078__SOLUTION3_H_
#define CPP_0078__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<vector<int>> ans;
	vector<int> nums;

	void dfs(vector<int> &num, int i) {
		ans.push_back(num);
		if (i == nums.size()) return;

		for (int j = i; j < nums.size(); ++j) {
			num.push_back(nums[j]);
			dfs(num, j + 1);
			num.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		this->nums = nums;
		vector<int> num;
		dfs(num, 0);
		return ans;
	}
};

#endif //CPP_0078__SOLUTION3_H_
