/**
 * @author ooooo
 * @date 2021/5/1 20:05 
 */

#ifndef CPP_0403__SOLUTION2_H_
#define CPP_0403__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool canCross(vector<int> &stones) {
		int n = stones.size();
		vector<vector<int>> dp(n, vector<int>(n));
		dp[0][0] = true;
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				int step = stones[i] - stones[j];
				if (step <= j + 1) {
					dp[i][step] = dp[j][step] || dp[j][step - 1] || dp[j][step + 1];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (dp[n - 1][i]) return true;
		}
		return false;
	}
};

#endif //CPP_0403__SOLUTION2_H_
