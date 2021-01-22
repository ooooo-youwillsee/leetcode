/**
 * @author ooooo
 * @date 2021/1/22 22:45 
 */

#ifndef CPP_0989__SOLUTION1_H_
#define CPP_0989__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<int> addToArrayForm(vector<int> &A, int K) {
		vector<int> ans;
		int carry = 0, i = A.size() - 1;
		while (K) {
			int a = carry + K % 10;
			if (i >= 0) {
				a += A[i];
			}
			carry = a / 10;
			ans.push_back(a % 10);
			i--;
			K /= 10;
		}
		while (i >= 0) {
			int a = carry + A[i];
			carry = a / 10;
			ans.push_back(a % 10);
			i--;
		}
		if (carry) {
			ans.push_back(carry);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

#endif //CPP_0989__SOLUTION1_H_
