/**
 * @author ooooo
 * @date 2021/3/3 17:21 
 */

#ifndef CPP_1573__SOLUTION1_H_
#define CPP_1573__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	static constexpr int MOD = 1000000007;
	int numWays(string s) {
		long long n = s.size();
		int cnt = 0;
		for (auto c : s) {
			if (c == '1') {
				cnt++;
			}
		}

		if (cnt % 3 != 0) {
			return 0;
		}
		if (cnt == 0) {
			return ((n - 2) * (n - 1) / 2) % MOD;
		}

		int l1 = 0, l2 = 0;
		int curCnt = 0;
		while (curCnt < cnt / 3) {
			if (s[l1] == '1') {
				curCnt++;
			}
			l1++;
		}
		l2 = l1;
		while (s[l2] != '1') l2++;

		int r1 = n - 1, r2 = n - 1;
		curCnt = 0;
		while (curCnt < cnt / 3) {
			if (s[r2] == '1') {
				curCnt++;
			}
			r2--;
		}
		r1 = r2;
		while (s[r1] != '1') r1--;

		return (long long) (r2 - r1 + 1) * (long long) (l2 - l1 + 1) % MOD;
	}
};

#endif //CPP_1573__SOLUTION1_H_
