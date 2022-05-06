/**
 * @author ooooo
 * @date 2021/3/22 19:55 
 */

#ifndef CPP_1734__SOLUTION1_H_
#define CPP_1734__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<int> decode(vector<int> &encoded) {
		int n = encoded.size();
		int sum = 0;
		for (int i = 1; i <= n + 1; ++i) {
			sum ^= i;
		}

		for (int i = 0; i < n; i += 2) {
			sum ^= encoded[i];
		}
		vector<int> ans(n + 1);
		ans[n] = sum;
		for (int i = n - 1; i >= 0; --i) {
			ans[i] = encoded[i] ^ ans[i + 1];
		}
		return ans;
	}
};

#endif //CPP_1734__SOLUTION1_H_
