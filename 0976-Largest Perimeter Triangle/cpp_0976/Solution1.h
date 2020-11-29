/**
 * @author ooooo
 * @date 2020/11/29 09:20 
 */

#ifndef CPP_0976__SOLUTION1_H_
#define CPP_0976__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int largestPerimeter(vector<int> &A) {
		sort(A.begin(), A.end());
		for (int i = (int) A.size() - 1; i >= 2; --i) {
			if (A[i - 2] + A[i - 1] > A[i]) {
				return A[i - 2] + A[i - 1] + A[i];
			}
		}
		return 0;
	}
};

#endif //CPP_0976__SOLUTION1_H_
