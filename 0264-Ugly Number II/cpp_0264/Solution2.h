/**
 * @author ooooo
 * @date 2021/4/11 15:17 
 */

#ifndef CPP_0264__SOLUTION2_H_
#define CPP_0264__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	using ll = long long;
	int nthUglyNumber(int n) {
		vector<ll> dp(n, 1);
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 0; i < n - 1; i++) {
			ll a = dp[p2] * 2, b = dp[p3] * 3, c = dp[p5] * 5;
			ll v = min(a, min(b, c));
			dp[i + 1] = v;
			if (v == a) {
				p2++;
			}
			if (v == b) {
				p3++;
			}
			if (v == c) {
				p5++;
			}
		}
		return dp[n - 1];
	}
};

#endif //CPP_0264__SOLUTION2_H_
