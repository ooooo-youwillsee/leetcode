/**
 * @author ooooo
 * @date 2021/2/15 17:56 
 */

#ifndef CPP_1031__SOLUTION2_H_
#define CPP_1031__SOLUTION2_H_

#include <vector>

using namespace std;

class Solution {
 public:

	vector<int> preSum;

	int maxSum(vector<int> &A, int L, int M) {
		int n = A.size();
		// dp[i][0] 表示前L个连续的子数组最大和
		// dp[i][1] 表示后M个连续的子数组最大和
		vector<vector<int>> dp(n, vector<int>(2));
		int sum = preSum[L];
		dp[L - 1][0] = sum;
		for (int i = L; i < n; ++i) {
			sum = max(sum, preSum[i + 1] - preSum[i - L + 1]);
			dp[i][0] = sum;
		}

		sum = preSum[n] - preSum[n - M];
		dp[n - M][1] = sum;
		for (int i = n - M - 1; i >= 0; --i) {
			sum = max(sum, preSum[i + M] - preSum[i]);
			dp[i][1] = sum;
		}

		int ans = 0;
		for (int i = L - 1; i < n - M; ++i) {
			ans = max(ans, dp[i][0] + dp[i + 1][1]);
		}
		return ans;
	}

	int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
		preSum.assign(A.size() + 1, 0);
		for (int i = 0; i < A.size(); ++i) {
			preSum[i + 1] = preSum[i] + A[i];
		}
		// 两种情况
		return max(maxSum(A, L, M), maxSum(A, M, L));
	}
};

#endif //CPP_1031__SOLUTION2_H_
