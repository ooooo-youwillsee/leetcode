/**
 * @author ooooo
 * @date 2021/6/1 14:17 
 */

#ifndef CPP_1744__SOLUTION1_H_
#define CPP_1744__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	using LL = long long;
	vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
		int n = candiesCount.size();
		LL preSum[n + 1];
		memset(preSum, 0, sizeof(preSum));
		for (int i = 0; i < n; i++) {
			preSum[i + 1] = preSum[i] + candiesCount[i];
		}

		vector<bool> ans(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			auto q = queries[i];
			auto t = q[0], d = q[1] + 1, c = q[2];
			ans[i] = preSum[t] < (long long) d * (long long) c && preSum[t + 1] >= d;
		}
		return ans;
	}
};
#endif //CPP_1744__SOLUTION1_H_
