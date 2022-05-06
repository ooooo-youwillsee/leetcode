/**
 * @author ooooo
 * @date 2020/11/27 11:10 
 */

#ifndef CPP_0315__SOLUTION1_H_
#define CPP_0315__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<int> countSmaller(vector<int> &nums) {
		int n = nums.size();
		vector<int> ans(n), insert;
		for (int i = n - 1; i >= 0; --i) {
			auto it = lower_bound(insert.begin(), insert.end(), nums[i]);
			ans[i] = it - insert.begin();
			insert.insert(insert.begin() + ans[i], nums[i]);
		}
		return ans;
	}
};

#endif //CPP_0315__SOLUTION1_H_
