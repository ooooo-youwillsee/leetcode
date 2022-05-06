/**
 * @author ooooo
 * @date 2021/2/19 09:53 
 */

#ifndef CPP_1004__SOLUTION2_H_
#define CPP_1004__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
	int longestOnes(vector<int> &A, int K) {
		int n = A.size();
		int ans = 0;
		int l = 0, r = 0;
		int cnt0 = 0;
		while (r < n) {
			if (A[r] == 0) {
				cnt0++;
			}
			while (cnt0 > K) {
				if (A[l] == 0) {
					cnt0--;
				}
				l++;
			}
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;
	}
};

#endif //CPP_1004__SOLUTION2_H_
