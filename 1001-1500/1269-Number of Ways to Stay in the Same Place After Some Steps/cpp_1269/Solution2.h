/**
 * @author ooooo
 * @date 2021/5/14 21:06 
 */

#ifndef CPP_1269__SOLUTION2_H_
#define CPP_1269__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	const int mod = 1e9 + 7;
	int numWays(int steps, int arrLen) {
		int maxJ = min(arrLen, steps);
		vector<vector<long long>> dp(steps + 1, vector<long long>(maxJ, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= steps; i++) {
			for (int j = 0; j < maxJ; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - 1 >= 0) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
				}
				if (j + 1 < maxJ) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
				}
			}
		}

		return dp[steps][0];
	}
};

#endif //CPP_1269__SOLUTION2_H_
