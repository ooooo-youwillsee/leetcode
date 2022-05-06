/**
 * @author ooooo
 * @date 2020/9/30 16:54 
 */

#ifndef CPP_0941__SOLUTION1_H_
#define CPP_0941__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool validMountainArray(vector<int> &A) {
		if (A.size() < 3) return false;

		bool incr = false, decr = false;
		for (int i = 1; i < A.size(); ++i) {
			if (A[i] == A[i - 1]) return false;
			if (A[i] > A[i - 1]) {
				if (decr) return false;
				incr = true;
			} else {
				if (!incr) return false;
				decr = true;
			}
		}
		return incr && decr;
	}
};

#endif //CPP_0941__SOLUTION1_H_
