/**
 * @author ooooo
 * @date 2020/11/27 10:05 
 */

#ifndef CPP_0454__SOLUTION1_H_
#define CPP_0454__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
		unordered_map<int, int> m1;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < B.size(); ++j) {
				m1[A[i] + B[j]]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < C.size(); ++i) {
			for (int j = 0; j < D.size(); ++j) {
				int x = C[i] + D[j];
				ans += m1[-x];
			}
		}
		return ans;
	}
};

#endif //CPP_0454__SOLUTION1_H_
