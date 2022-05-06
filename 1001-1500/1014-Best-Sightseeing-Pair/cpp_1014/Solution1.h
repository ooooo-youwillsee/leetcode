/**
 * @author ooooo
 * @date 2021/2/11 14:39 
 */

#ifndef CPP_1014__SOLUTION1_H_
#define CPP_1014__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;


class Solution {
 public:
	int maxScoreSightseeingPair(const vector<int> &A) {
		int n = A.size();
		vector<int> maxNums(n, 0);
		maxNums[n - 1] = A[n - 1] - (n - 1);
		for (int i = A.size() - 2; i >= 0; --i) {
			maxNums[i] = max(A[i] - i, maxNums[i + 1]);
		}

		int ans = INT_MIN, cur = 0;
		for (int i = 0; i < A.size() - 1; ++i) {
			cur = max(cur, A[i] + i);
			ans = max(ans, cur + maxNums[i + 1]);
		}
		return ans;
	}
};

#endif //CPP_1014__SOLUTION1_H_
