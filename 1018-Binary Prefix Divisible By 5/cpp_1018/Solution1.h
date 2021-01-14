/**
 * @author ooooo
 * @date 2021/1/14 09:04 
 */

#ifndef CPP_1018__SOLUTION1_H_
#define CPP_1018__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

// 101 -> 5
// 1010 -> 10
// 1111 -> 8 + 4 + 2 + 1 = 15
// 10100 -> 8 + 4 + 2 + 1 = 20

class Solution {
 public:
	vector<bool> prefixesDivBy5(vector<int> &A) {
		int i = 0;
		vector<bool> ans;
		for (int j = 0; j < A.size(); ++j) {
			i = ((i << 1) + A[j]) % 5;
			ans.push_back(i == 0);
		}
		return ans;
	}
};

#endif //CPP_1018__SOLUTION1_H_
