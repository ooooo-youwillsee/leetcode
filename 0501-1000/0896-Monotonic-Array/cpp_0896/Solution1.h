/**
 * @author ooooo
 * @date 2020/9/30 15:57 
 */

#ifndef CPP_0896__SOLUTION1_H_
#define CPP_0896__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool isMonotonic(vector<int> &A) {
		if (A.size() <= 2) return true;
		bool is_incr = A[0] <= A[A.size() - 1];
		for (int i = 1; i < A.size(); ++i) {
			if (is_incr) {
				if (A[i] < A[i - 1]) return false;
			} else {
				if (A[i] > A[i - 1]) return false;
			}
		}
		return true;
	}
};

#endif //CPP_0896__SOLUTION1_H_
