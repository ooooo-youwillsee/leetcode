/**
 * @author ooooo
 * @date 2020/9/8 12:06 
 */

#ifndef CPP_0077__SOLUTION1_H_
#define CPP_0077__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:

	vector<vector<int>> ans;

	void dfs(vector<int> &vec, int i, int n, int k) {
		if (vec.size() == k) {
			ans.push_back(vec);
			return;
		}
		while (i <= n) {
			vec.push_back(i);
			dfs(vec, i + 1, n, k);
			vec.pop_back();
			i++;
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<int> vec;
		dfs(vec, 1, n, k);
		return ans;
	}
};

#endif //CPP_0077__SOLUTION1_H_
