/**
 * @author ooooo
 * @date 2020/9/30 16:20 
 */

#ifndef CPP_0914__SOLUTION1_H_
#define CPP_0914__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:

	/**
	 * 求最大公约数
	 */
	int gcd(int x, int y) {
		if (x < y) return gcd(y, x);
		if (x % y == 0) return y;
		return gcd(y, x % y);
	}

	bool hasGroupsSizeX(vector<int> &deck) {
		unordered_map<int, int> m;
		for (auto &v : deck) {
			m[v]++;
		}
		int c = -1;
		for (auto &[k, v] :  m) {
			if (c == -1) {
				c = v;
			} else {
				c = gcd(c, v);
			}
			if (c < 2) return false;
		}
		return true;
	}
};

#endif //CPP_0914__SOLUTION1_H_
