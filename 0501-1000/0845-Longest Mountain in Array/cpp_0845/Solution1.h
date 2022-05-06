/**
 * @author ooooo
 * @date 2020/10/25 10:28 
 */

#ifndef CPP_0845__SOLUTION1_H_
#define CPP_0845__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dp
 */
class Solution {
 public:
	int longestMountain(vector<int> &A) {
		if (A.size() < 3)return 0;
		int m = A.size();
		vector<int> dp(m, 0), top(m, 1);
		int ans = 0;
		for (int i = 1; i < m; ++i) {
			for (int j = i; j >= 0; --j) {
				if (A[j] < A[i]) {
					top[i] = max(top[i], top[j] + 1);
				} else if (A[j] > A[i] && top[j] >= 2) {
					dp[i] = max(dp[i], dp[j] + 1);
					dp[i] = max(dp[i], top[j] + 1);
					ans = max(dp[i], ans);
					if (dp[i] > i) break;
				}
			}
			//cout << i << " " << dp[i] << endl;
		}
		return ans;
	}
};

#endif //CPP_0845__SOLUTION1_H_
