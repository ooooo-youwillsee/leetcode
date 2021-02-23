/**
 * @author ooooo
 * @date 2021/2/23 13:40 
 */

#ifndef CPP_1052__SOLUTION1_H_
#define CPP_1052__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int x) {
		int n = customers.size();
		// preSum 表示不生气  preGrumpSum表示生气
		vector<int> preSum(n + 1), preGrumpSum(n + 1);

		for (int i = 0; i < n; ++i) {
			preSum[i + 1] = preSum[i] + customers[i];
			preGrumpSum[i + 1] = preGrumpSum[i] + (grumpy[i] == 1 ? 0 : customers[i]);
		}

		int ans = 0;
		for (int i = 0; i + x - 1 < n; ++i) {
			ans = max(ans, preSum[i + x] - preSum[i] + preGrumpSum[i] + preGrumpSum[n] - preGrumpSum[i + x]);
		}
		return ans;
	}
};

#endif //CPP_1052__SOLUTION1_H_
