/**
 * @author ooooo
 * @date 2021/4/10 20:39 
 */

#ifndef CPP_029__SOLUTION1_H_
#define CPP_029__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	typedef long long ll;
	ll work(ll n, ll a, ll b) {
		ll q = min(min(a, b), min(n - a + 1, n - b + 1));
		ll ans;
		if (a <= b) {
			q--;
			ans = 4 * (n - q) * q + a + b - 2 * (q + 1) + 1;
		} else
			ans = 4 * (n - q) * q - a - b + 2 * q + 1;
		return ans % 9;
	}

	int orchestraLayout(int n, int x, int y) {
		int ans = work(n, x + 1, y + 1);
		// 没有0这个数字
		return ans == 0 ? 9 : ans;
	}
};

#endif //CPP_029__SOLUTION1_H_
