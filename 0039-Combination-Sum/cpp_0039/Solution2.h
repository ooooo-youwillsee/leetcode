/**
 * @author ooooo
 * @date 2020/9/9 22:25 
 */

#ifndef CPP_0039__SOLUTION2_H_
#define CPP_0039__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<vector<int>> ans;
	vector<int> candidates;

	void dfs(vector<int> &vec, int i, int sum) {
		if (sum < 0) return;
		if (sum == 0) {
			ans.push_back(vec);
			return;
		}

		while (i < candidates.size()) {
			if (sum < candidates[i]) return;
			vec.push_back(candidates[i]);
			dfs(vec, i, sum - candidates[i]);
			vec.pop_back();
			i++;
		}
	}

	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<int> vec;
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		dfs(vec, 0, target);
		return ans;
	}
};

#endif //CPP_0039__SOLUTION2_H_
