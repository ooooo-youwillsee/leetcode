/**
 * @author ooooo
 * @date 2021/2/15 17:39 
 */

#ifndef CPP_1031__SOLUTION1_H_
#define CPP_1031__SOLUTION1_H_

#include <vector>

using namespace std;

/**
 * 滑动窗口
 */
class Solution {
 public:

	int maxSum(vector<int> &A, int l, int r, int len) {
		if (r - l + 1 < len) {
			return -1;
		}
		int sum = 0;
		int start = l, end = l;
		int ans = 0;
		while (end <= r) {
			sum += A[end];
			if (end - start + 1 < len) {
				end++;
				continue;
			}
			ans = max(ans, sum);
			sum -= A[start];
			start++;
			end++;
		}
		return ans;
	}

	int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
		int l = 0, r = 0;
		int ans = 0;
		int sumL = 0, sumM = 0;
		while (r < A.size()) {
			sumL += A[r];
			if (r - l + 1 < L) {
				r++;
				continue;
			}

			sumM = max(maxSum(A, 0, l - 1, M), maxSum(A, r + 1, A.size() - 1, M));
			ans = max(ans, sumL + sumM);
			sumL -= A[l];
			l++;
			r++;
		}
		return ans;
	}
};

#endif //CPP_1031__SOLUTION1_H_
