/**
 * @author ooooo
 * @date 2020/10/5 13:15 
 */

#ifndef CPP_0718__SOLUTION2_H_
#define CPP_0718__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int findLength(vector<int> &A, vector<int> &B) {
		int m = A.size(), n = B.size();
		int ans = 0;
		vector<int> dp(n + 1, 0);
		// cout<<endl;
		int prev = 0, help = 0;
		for (int i = 0; i < m; i++) {
			help = 0;
			for (int j = 0; j < n; j++) {
				prev = help;
				help = dp[j + 1]; // 保留上个状态，避免被覆盖
				if (A[i] == B[j]) {
					dp[j + 1] = prev + 1;
					ans = max(ans, dp[j + 1]);
				} else {
					dp[j + 1] = 0;
				}
				// cout << " i: "<< i <<" j: " << j << " : " << dp[j+1] << "\t ";
			}
			// cout<< endl;
		}
		return ans;
	}
};

#endif //CPP_0718__SOLUTION2_H_
