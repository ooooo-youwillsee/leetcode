/**
 *
 * @author ooooo
 * @date 2021/5/25 22:13 
 */

#ifndef CPP_1863__SOLUTION1_H_
#define CPP_1863__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
	int ans = 0;
	void dfs(vector<int> &nums, int i, int sum) {
		ans += sum;
		for (int j = i; j < nums.size(); j++) {
			dfs(nums, j + 1, sum ^ nums[j]);
		}
	}

	int subsetXORSum(vector<int> &nums) {
		dfs(nums, 0, 0);
		return ans;

	};
};

#endif //CPP_1863__SOLUTION1_H_
