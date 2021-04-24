/**
 * @author ooooo
 * @date 2021/4/24 08:34 
 */

#ifndef CPP_0377__SOLUTION1_H_
#define CPP_0377__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:

	int dfs(vector<int> &nums, int target) {
		if (memo.find(target) != memo.end()) return memo[target];
		if (target == 0) return memo[target] = 1;
		if (target < 0) return memo[target] = 0;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans += dfs(nums, target - nums[i]);
		}
		return memo[target] = ans;
	}
	unordered_map<int, int> memo;
	int combinationSum4(vector<int> &nums, int target) {
		return dfs(nums, target);
	}
};

#endif //CPP_0377__SOLUTION1_H_
