/**
 * @author ooooo
 * @date 2020/9/11 11:27 
 */

#ifndef CPP_0216__SOLUTION1_H_
#define CPP_0216__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<vector<int>> ans;

	void dfs(vector<int> &vec, int i, int k, int n) {
		if (vec.size() == k) {
			if (n == 0)
				ans.push_back(vec);
			return;
		}
		while (i <= 9) {
			if (n < i) return;
			vec.push_back(i);
			dfs(vec, i + 1, k, n - i);
			vec.pop_back();
			i++;
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> vec;
		dfs(vec, 1, k, n);
		return ans;
	}
};

#endif //CPP_0216__SOLUTION1_H_
