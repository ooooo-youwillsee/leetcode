/**
 * @author ooooo
 * @date 2021/2/14 09:55 
 */

#ifndef CPP_1680__SOLUTION1_H_
#define CPP_1680__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:

	static const long MOD = 1000000007;

	int concatenatedBinary(int n) {
		long ans = 0;
		for (int i = 1; i <= n; ++i) {

			int x = i, y = 0, count = 0;
			while (x) {
				y += (x % 2) << count;
				x /= 2;
				count++;
			}
			ans = (((ans << count) % MOD) + y) % MOD;
		}
		return ans;
	}
};

#endif //CPP_1680__SOLUTION1_H_
