/**
 * @author ooooo
 * @date 2021/1/24 09:28 
 */

#ifndef CPP_1718__SOLUTION1_H_
#define CPP_1718__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:

	vector<int> nums;
	vector<int> ans;

	bool dfs(int i) {
		if (i >= ans.size()) return true;
		if (ans[i] != -1) return dfs(i + 1);
		// 从最大的数字开始选择
		for (int k = 0; k < nums.size(); k++) {
			int num = nums[k];
			// 这个数字已经被选中
			if (num == -1) continue;
			if (num != 1) {
				if (i + num >= ans.size() || ans[i + num] != -1) {
					continue;
				}
				ans[i + num] = num;
			}
			ans[i] = num;
			nums[k] = -1;
			if (dfs(i + 1)) return true;
			ans[i] = -1;
			nums[k] = num;
			if (num != 1 && i + num < ans.size()) {
				ans[i + num] = -1;
			}
		}
		return false;
	}

	vector<int> constructDistancedSequence(int n) {
		for (int i = 1; i <= n; ++i) {
			nums.push_back(i);
		}
		sort(nums.begin(), nums.end(), greater<int>());
		ans.assign(2 * n - 1, -1);
		dfs(0);
		return ans;
	}
};

#endif //CPP_1718__SOLUTION1_H_
