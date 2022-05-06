/**
 * @author ooooo
 * @date 2020/10/5 13:13 
 */

#ifndef CPP_0718__SOLUTION1_H_
#define CPP_0718__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二维数组
 */
class Solution {
 public:
	int findLength(vector<int> &A, vector<int> &B) {
		int m = A.size(), n = B.size();
		int ans = 0;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < m; i++) {
			dp[i][0] = B[0] == A[i] ? 1 : 0;
		}
		for (int j = 0; j < n; j++) {
			dp[0][j] = A[0] == B[j] ? 1 : 0;
		}
		// cout << endl;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (A[i] == B[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = 0;
				}
				ans = max(ans, dp[i][j]);
				// cout << " i: "<< i <<" j: " << j << " : " << dp[i][j] << "\t ";
			}
			//cout << endl;
		}
		return ans;
	}
};

#endif //CPP_0718__SOLUTION1_H_
