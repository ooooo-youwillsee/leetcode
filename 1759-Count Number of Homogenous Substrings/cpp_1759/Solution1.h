/**
 * @author ooooo
 * @date 2021/2/21 19:07 
 */

#ifndef CPP_1759__SOLUTION1_H_
#define CPP_1759__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	static const long MOD = 1000000007;

	int countHomogenous(string s) {
		s += "#";
		int n = s.size();
		long long cnt = 1;
		long long ans = 0;
		for (int r = 1; r < n; ++r) {
			if (s[r] == s[r - 1]) {
				cnt++;
			} else {
				ans = (ans + (1 + cnt) * cnt / 2) % MOD;
				cnt = 1;
			}
		}
		return ans;
	}
};

#endif //CPP_1759__SOLUTION1_H_
