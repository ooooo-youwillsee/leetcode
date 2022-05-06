/**
 * @author ooooo
 * @date 2020/9/10 14:39 
 */

#ifndef CPP_0040__SOLUTION1_H_
#define CPP_0040__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	struct Vec_Hash {
		size_t operator()(vector<int> vec) const {
			size_t ret = 0;
			for (int i = 0; i < vec.size(); ++i) {
				ret += hash<int>()(vec[i]);
			}
			return ret;
		}
	};

	vector<int> candidates;
	unordered_set<vector<int>, Vec_Hash> ans;

	void dfs(vector<int> &vec, int i, int target) {
		if (target == 0) {
			ans.insert(vec);
			return;
		}

		while (i < candidates.size()) {
			if (target < candidates[i]) return;
			vec.push_back(candidates[i]);
			dfs(vec, i + 1, target - candidates[i]);
			vec.pop_back();
			i++;
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		vector<int> vec;
		dfs(vec, 0, target);
		vector<vector<int>> nums;
		for (auto &num: ans) nums.push_back(num);
		return nums;
	}
};

#endif //CPP_0040__SOLUTION1_H_
