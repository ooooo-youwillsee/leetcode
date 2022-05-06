/**
 * @author ooooo
 * @date 2020/10/25 13:00 
 */

#ifndef CPP_0845__SOLUTION2_H_
#define CPP_0845__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int longestMountain(vector<int> &A) {
		if (A.size() < 3)return 0;
		int m = A.size();
		vector<int> left(m, 0);
		for (int i = 1; i < A.size(); ++i) {
			left[i] = A[i - 1] < A[i] ? left[i - 1] + 1 : 0;
		}
		vector<int> right(m);
		for (int i = m - 2; i >= 0; --i) {
			right[i] = A[i + 1] < A[i] ? right[i + 1] + 1 : 0;
		}
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			if (left[i] > 0 && right[i] > 0) {
				ans = max(ans, left[i] + right[i] + 1);
			}
		}
		return ans;
	}
};

#endif //CPP_0845__SOLUTION2_H_
