/**
 * @author ooooo
 * @date 2021/5/21 07:35 
 */

#ifndef CPP_1035__SOLUTION1_H_
#define CPP_1035__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
		int m = nums1.size(), n = nums2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (nums1[i] == nums2[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				} else {
					dp[i + 1][j + 1] = max(max(dp[i][j], dp[i + 1][j]), dp[i][j + 1]);
				}
			}
		}
		return dp[m][n];
	}
};

#endif //CPP_1035__SOLUTION1_H_
